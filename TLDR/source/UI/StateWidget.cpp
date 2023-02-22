#include "../../include/UI/StateWidget.h"
//StateWidget
StateWidget::StateWidget(QWidget* parent) :QFrame(parent) {
	this->setObjectName("StateWidget");
	TitleLabel = new QLabel("正在连接到服务器",this);
	TitleLabel->setObjectName("Title_2");
	TitleLabel->setAlignment(Qt::AlignCenter);
	StateEdit = new QTextEdit(this);
	ConfirmButton = new QPushButton("重试",this);
	ConfirmButton->setDisabled(true);
	
	MainLayout = new QGridLayout(this);
	MainLayout->addWidget(TitleLabel, 0, 0, 1, 1);
	MainLayout->addWidget(StateEdit, 1, 0, 1, 1);
	MainLayout->addWidget(ConfirmButton, 2, 0, 1, 1);
	this->setLayout(MainLayout);
}