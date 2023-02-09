#include "../../include/UI/MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :QWidget(parent) {
	MainLayout = new QGridLayout(this);
	MainLayout->setSpacing(0);
	MainLayout->setContentsMargins(0, 0, 0, 0);
	InputArea = new InputWidget(this);
	MainLayout->addWidget(InputArea, 0, 0, 1, 1);
}