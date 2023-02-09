#include "../../include/UI/InputWidget.h"

InputWidget::InputWidget(QWidget* parent) :QWidget(parent) {
	this->setObjectName("InputWidget");
	MainLayout = new QGridLayout(this);
	
	TitleLabel = new QLabel(this);
	TitleLabel->setObjectName("Title_1");
	TitleLabel->setText("新闻标题生成器");
	MainLayout->addWidget(TitleLabel, 0, 0, 1, 2);
	
	InputDescriptionLabel = new QLabel(this);
	InputDescriptionLabel->setObjectName("Text");
	InputDescriptionLabel->setText("新闻正文");
	MainLayout->addWidget(InputDescriptionLabel, 1, 0, 1, 1);
	
	InputEdit = new QTextEdit(this);
	InputEdit->setObjectName("InputEdit");
	MainLayout->addWidget(InputEdit, 2, 0, 1, 2);
	
	ConfirmButton = new QPushButton(this);
	ConfirmButton->setObjectName("Button");
	ConfirmButton->setText("生成标题");
	MainLayout->addWidget(ConfirmButton, 3, 0, 1, 2);
	
	StateLabel = new QLabel(this);
	StateLabel->setObjectName("Notice");
	StateLabel->setText("后台状态");
	MainLayout->addWidget(StateLabel, 4, 0, 1, 2);

	OutputDesciptionLabel = new QLabel(this);
	OutputDesciptionLabel->setObjectName("Text");
	OutputDesciptionLabel->setText("标题输出");
	MainLayout->addWidget(OutputDesciptionLabel, 5, 0, 1, 1);

	OutputEdit = new QTextEdit(this);
	OutputEdit->setObjectName("OutputEdit");
	OutputEdit->setReadOnly(true);
	MainLayout->addWidget(OutputEdit, 6, 0, 1, 2);
	
	RawQSS = GlobalStyle::getAllNormalStyle() + GlobalStyle::InputWidget;
	this->setStyleSheet(GlobalStyle::QSSExtensionAUTOPR(RawQSS, this));
}

void InputWidget::resizeEvent(QResizeEvent* event) {
	this->setStyleSheet(GlobalStyle::QSSExtensionAUTOPR(RawQSS, this));
}