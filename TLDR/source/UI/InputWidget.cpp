#include "../../include/UI/InputWidget.h"
//NumInputLine

NumInputLine::NumInputLine(QWidget* parent) :QFrame(parent) {
	this->setObjectName("NumInputLine");
	InputEdit = new QLineEdit(this);
	PlusButton = new QPushButton("+", this);
	PlusButton->setObjectName("Button_Plus");
	MinusButton = new QPushButton("-", this);
	MinusButton->setObjectName("Button_Minus");
	MinValue = 0;
	MaxValue = 100;
	Step = 1;
	InputEdit->setAlignment(Qt::AlignCenter);
	InputEdit->setStyleSheet(GlobalStyle::InputEdit);
	PlusButton->setStyleSheet(GlobalStyle::Button_Plus);
	MinusButton->setStyleSheet(GlobalStyle::Button_Minus);
	QObject::connect(PlusButton, &QPushButton::clicked, this, &NumInputLine::PlusButtonClicked);
	QObject::connect(MinusButton, &QPushButton::clicked, this, &NumInputLine::MinusButtonClicked);
	this->setMinimumSize(100, 30);
	//this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
}
void NumInputLine::resizeEvent(QResizeEvent* event) {
	InputEdit->setGeometry(this->height(), 0, this->width() - this->height()*2, this->height());
	PlusButton->setGeometry(0, 0, this->height(), this->height());
	MinusButton->setGeometry(this->width() - this->height(), 0, this->height(), this->height());
}
void NumInputLine::setMinValue(float min) {
	MinValue = min;
}
void NumInputLine::setMaxValue(float max) {
	MaxValue = max;
}
void NumInputLine::setStep(float step) {
	Step = step;
}
void NumInputLine::setValue(float value) {
	InputEdit->setText(QString::number(value));
}
float NumInputLine::getValue() {
	return InputEdit->text().toFloat();
}
void NumInputLine::PlusButtonClicked() {
	float value = InputEdit->text().toFloat();
	value += Step;
	if (value > MaxValue) {
		value = MaxValue;
	}
	InputEdit->setText(QString::number(value));
}
void NumInputLine::MinusButtonClicked() {
	float value = InputEdit->text().toFloat();
	value -= Step;
	if (value < MinValue) {
		value = MinValue;
	}
	InputEdit->setText(QString::number(value));
}

InputWidget::InputWidget(QWidget* parent) :QWidget(parent) {
	this->setObjectName("InputWidget");
	MainLayout = new QGridLayout(this);
	
	InputDescriptionLabel = new QLabel(this);
	InputDescriptionLabel->setText("新闻正文");
	MainLayout->addWidget(InputDescriptionLabel, 1, 0, 1, 1);
	
	InputEdit = new QTextEdit(this);
	InputEdit->setObjectName("TextEdit");
	MainLayout->addWidget(InputEdit, 2, 0, 5, 2);
	
	Settings_batch_size_Label = new QLabel("Batch Size: 3", this);
	MainLayout->addWidget(Settings_batch_size_Label, 7, 0, 1, 2);
	
	Settings_batch_size_Scroller = new QScrollBar(Qt::Horizontal, this);
	Settings_batch_size_Scroller->setMinimum(1);
	Settings_batch_size_Scroller->setMaximum(10);
	Settings_batch_size_Scroller->setValue(3);
	Settings_batch_size_Scroller->setSingleStep(1);
	Settings_batch_size_Scroller->setObjectName("InputScroller");
	Settings_batch_size_Scroller->setMinimumHeight(40);
	MainLayout->addWidget(Settings_batch_size_Scroller, 8, 0, 1, 2);
	
	connect(Settings_batch_size_Scroller, &QSlider::valueChanged, [=](int value) {
		Settings_batch_size_Label->setText("Batch Size: " + QString::number(value)); });
	
	Settings_top_k_Label = new QLabel("Top K: 3", this);
	MainLayout->addWidget(Settings_top_k_Label, 9, 0, 1, 2);
	
	Settings_top_k_Scroller = new QScrollBar(Qt::Horizontal, this);
	Settings_top_k_Scroller->setMinimum(1);
	Settings_top_k_Scroller->setMaximum(10);
	Settings_top_k_Scroller->setValue(3);
	Settings_top_k_Scroller->setSingleStep(1);
	Settings_top_k_Scroller->setObjectName("InputScroller");
	Settings_top_k_Scroller->setMinimumHeight(40);
	MainLayout->addWidget(Settings_top_k_Scroller, 10, 0, 1, 2);
	
	connect(Settings_top_k_Scroller, &QSlider::valueChanged, [=](int value) {
		Settings_top_k_Label->setText("Top K: " + QString::number(value)); });
	
	Settings_generate_max_len_Label = new QLabel("Max Length", this);
	MainLayout->addWidget(Settings_generate_max_len_Label, 11, 0, 1, 1);
	
	Settings_generate_max_len_Line = new NumInputLine(this);
	Settings_generate_max_len_Line->setMinValue(10);
	Settings_generate_max_len_Line->setMaxValue(50);
	Settings_generate_max_len_Line->setStep(1);
	Settings_generate_max_len_Line->setValue(30);
	MainLayout->addWidget(Settings_generate_max_len_Line, 12, 0, 1, 1);
	
	Settings_repetition_penalty_Label = new QLabel("Repetition Penalty", this);
	MainLayout->addWidget(Settings_repetition_penalty_Label, 13, 0, 1, 1);
	
	Settings_repetition_penalty_Line = new NumInputLine(this);
	Settings_repetition_penalty_Line->setMinValue(1);
	Settings_repetition_penalty_Line->setMaxValue(10);
	Settings_repetition_penalty_Line->setStep(0.1);
	Settings_repetition_penalty_Line->setValue(1.2);
	MainLayout->addWidget(Settings_repetition_penalty_Line, 14, 0, 1, 1);
	
	Settings_top_p_Label = new QLabel("Top P", this);
	MainLayout->addWidget(Settings_top_p_Label, 15, 0, 1, 1);
	
	Settings_top_p_Line = new NumInputLine(this);
	Settings_top_p_Line->setMinValue(0.1);
	Settings_top_p_Line->setMaxValue(1);
	Settings_top_p_Line->setStep(0.1);
	Settings_top_p_Line->setValue(0.95);
	MainLayout->addWidget(Settings_top_p_Line, 16, 0, 1, 1);

	ConfirmButton = new QPushButton("生成", this);
	ConfirmButton->setObjectName("Button");
	ConfirmButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
	MainLayout->addWidget(ConfirmButton, 13, 1, 3, 1);

}

void InputWidget::resizeEvent(QResizeEvent* event) {
	
}