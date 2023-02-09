#pragma once
#include "../StyleSheet/StyleSheet.h"
#include "../ginclude.h"

class InputWidget :public QWidget
{
private:
	QString RawQSS;
	QLabel* TitleLabel;
	QLabel* InputDescriptionLabel;
	QTextEdit* InputEdit;
	QPushButton* ConfirmButton;
	QLabel* StateLabel;
	QLabel* OutputDesciptionLabel;
	QTextEdit* OutputEdit;
	QGridLayout* MainLayout;
public:
	InputWidget(QWidget* parent = Q_NULLPTR);
	void resizeEvent(QResizeEvent* event);
};