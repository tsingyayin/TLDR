#pragma once
#include "../StyleSheet/StyleSheet.h"
#include "../ginclude.h"
class NumInputLine :public QFrame
{
	Q_OBJECT;
private:
	QLineEdit* InputEdit;
	QPushButton* PlusButton;
	QPushButton* MinusButton;
	float MinValue;
	float MaxValue;
	float Step;
public:
	NumInputLine(QWidget* parent = Q_NULLPTR);
	void resizeEvent(QResizeEvent* event);
	void setMinValue(float min);
	void setMaxValue(float max);
	void setStep(float step);
	void setValue(float value);
	float getValue();
public slots:
	void PlusButtonClicked();
	void MinusButtonClicked();
};

class InputWidget :public QWidget
{
public:
	QLabel* InputDescriptionLabel;
	QTextEdit* InputEdit;
	QGridLayout* MainLayout;
	QLabel* Settings_batch_size_Label;
	QScrollBar* Settings_batch_size_Scroller;
	QLabel* Settings_generate_max_len_Label;
	NumInputLine* Settings_generate_max_len_Line;
	QLabel* Settings_repetition_penalty_Label;
	NumInputLine* Settings_repetition_penalty_Line;
	QLabel* Settings_top_k_Label;
	QScrollBar* Settings_top_k_Scroller;
	QLabel* Settings_top_p_Label;
	NumInputLine* Settings_top_p_Line;
	QPushButton* ConfirmButton;
	InputWidget(QWidget* parent = Q_NULLPTR);
	void resizeEvent(QResizeEvent* event);
};