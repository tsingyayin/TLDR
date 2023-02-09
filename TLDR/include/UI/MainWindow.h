#pragma once
#include "InputWidget.h"

class MainWindow :public QWidget
{
	Q_OBJECT
private:
	InputWidget* InputArea;
	QGridLayout* MainLayout;
public:
	MainWindow(QWidget* parent = Q_NULLPTR);
};