#include "../../include/UI/MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :QOpenGLWidget(parent) {
	BackgroundLabel = new QLabel(this);
	BackgroundLabel->setObjectName("BackgroundLabel");
	BackgroundLabel->setStyleSheet("QLabel#BackgroundLabel {border-image:url(:/main/resource/BG.jpg)}");
	BackgroundBlurEffect = new QGraphicsBlurEffect(this);
	BackgroundLabel->setGraphicsEffect(BackgroundBlurEffect);
	BackgroundBlurEffect->setBlurRadius(30);
	
	
	MainLayout = new QGridLayout(this);
	MainLayout->setSpacing(0);
	MainLayout->setContentsMargins(20, 20, 20, 20);
	InputArea = new InputWidget(this);
	connect(InputArea->ConfirmButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
	
	MainLayout->addWidget(InputArea, 0, 0, 1, 1);
	StateCover = new QLabel(this);
	StateCover->setObjectName("GrayCover");
	StateCover->setStyleSheet(GlobalStyle::GrayCover);
	StateArea = new StateWidget(this);
	StateArea->setObjectName("StateArea");
	connect(this->StateArea->ConfirmButton, &QPushButton::clicked, this, &MainWindow::onStateButtonClicked);
	AppServer = new ServerConnection(this);
	connect(AppServer, SIGNAL(DataReceived(QJsonDocument)), this, SLOT(onDataReceived(QJsonDocument)));
	connect(AppServer, SIGNAL(serverConnected()), this, SLOT(onConnected()));
	connect(AppServer, SIGNAL(serverDisconnected()), this, SLOT(onDisconnected()));
	connect(AppServer, SIGNAL(serverConnectionFailed()), this, SLOT(onConnectionFailed()));
	RawQSS = GlobalStyle::getAllNormalStyle() + GlobalStyle::InputWidget + GlobalStyle::StateWidget;
	this->setStyleSheet(GlobalStyle::QSSExtensionAUTOPR(RawQSS, this));
}

void MainWindow::resizeEvent(QResizeEvent* event) {
	BackgroundLabel->setGeometry(0, 0, this->width(), this->height());
	StateArea->setGeometry(this->width() * 0.1, this->height() * 0.2, this->width() * 0.8, this->height() * 0.6);
	StateCover->setGeometry(0, 0, this->width(),this->height());
	this->setStyleSheet(GlobalStyle::QSSExtensionAUTOPR(RawQSS, this));
}

float MainWindow::getAnimationPercentage() {
	return 0;
}
void MainWindow::timerSetValue() {

}
void MainWindow::setAnimationPercentage(float AnimationPercentage) {

}
void MainWindow::onStateButtonClicked() {
	if (AppServer->isConnected()) {
		StateArea->hide();
		StateCover->hide();
	}
	else {
		AppServer->tryConnection();
		StateArea->ConfirmButton->setDisabled(true);
	}
	
}
void MainWindow::onButtonClicked() {
	StateArea->show();
	StateCover->show();
	if (AppServer->isConnected()) {
		StateArea->TitleLabel->setText("正在生成");
		StateArea->ConfirmButton->setText("正在生成");
		StateArea->ConfirmButton->setDisabled(true);
		StateArea->StateEdit->clear();
		QJsonObject DataObject;
		DataObject["content"] = QJsonValue(this->InputArea->InputEdit->toPlainText());
		DataObject["batch_size"] = QJsonValue(this->InputArea->Settings_batch_size_Scroller->value());
		DataObject["generate_max_len"] = QJsonValue(this->InputArea->Settings_generate_max_len_Line->getValue());
		DataObject["repetition_penalty"] = QJsonValue(this->InputArea->Settings_repetition_penalty_Line->getValue());
		DataObject["top_k"] = QJsonValue(this->InputArea->Settings_top_k_Scroller->value());
		DataObject["top_p"] = QJsonValue(this->InputArea->Settings_top_p_Line->getValue());
		this->AppServer->sendData(QJsonDocument(DataObject));
		this->StateArea->TitleLabel->setText("正在生成");
	}
	else {
		this->StateArea->TitleLabel->setText("已断开与服务器的连接");
		this->StateArea->ConfirmButton->setText("重新连接");
		this->StateArea->ConfirmButton->setDisabled(true);
		AppServer->tryConnection();
	}
}
void MainWindow::onDataReceived(QJsonDocument data) {
	QJsonArray titles = data.object()["message"].toArray();
	QStringList titleList;
	for (int i = 0; i < titles.size(); i++) {
		titleList.append(titles[i].toString());
	}
	this->StateArea->TitleLabel->setText("生成完成");
	this->StateArea->StateEdit->setPlainText(titleList.join("\n"));
	this->StateArea->ConfirmButton->setText("关闭");
	this->StateArea->ConfirmButton->setEnabled(true);
}
void MainWindow::onConnected() {
	this->StateArea->TitleLabel->setText("已连接到服务器");
	this->StateArea->StateEdit->setPlainText("已经成功连接到服务器，点击下方按钮退出此页面");
	this->StateArea->ConfirmButton->setText("关闭");
	this->StateArea->ConfirmButton->setEnabled(true);
}
void MainWindow::onDisconnected() {
	this->StateArea->show();
	this->StateCover->show();
	this->StateArea->TitleLabel->setText("已断开与服务器的连接");
	this->StateArea->StateEdit->setPlainText("请单击下方按钮尝试重新连接");
	this->StateArea->ConfirmButton->setText("重新连接");
	this->StateArea->ConfirmButton->setEnabled(true);
}
void MainWindow::onConnectionFailed() {
	this->StateArea->show();
	this->StateCover->show();
	this->StateArea->TitleLabel->setText("连接服务器失败");
	this->StateArea->StateEdit->setPlainText("请单击下方按钮尝试重新连接\n"+this->AppServer->errorString());
	this->StateArea->ConfirmButton->setText("重新连接");
	this->StateArea->ConfirmButton->setEnabled(true);
}