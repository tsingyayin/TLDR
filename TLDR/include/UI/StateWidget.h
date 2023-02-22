#pragma once
#include "../ginclude.h"
#include "../StyleSheet/StyleSheet.h"

class StateWidget :public QFrame {
	Q_OBJECT;
public:
	QLabel* TitleLabel;
	QTextEdit* StateEdit;
	QPushButton* ConfirmButton;
	QGridLayout* MainLayout;
public:
	StateWidget(QWidget* parent = Q_NULLPTR);
};