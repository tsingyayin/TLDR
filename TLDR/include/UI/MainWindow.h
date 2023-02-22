#pragma once
#include "InputWidget.h"
#include "StateWidget.h"
#include "../Backend/ServerConnection.h"



class MainWindow :public QOpenGLWidget
{
	Q_OBJECT;
private:
	QLabel* BackgroundLabel;
	QGraphicsBlurEffect* BackgroundBlurEffect;
	StateWidget* StateArea;
	QLabel* StateCover;
	InputWidget* InputArea;
	QGridLayout* MainLayout;
	ServerConnection* AppServer;
	QString RawQSS;
public:
	MainWindow(QWidget* parent = Q_NULLPTR);
	void resizeEvent(QResizeEvent* event);
public slots:
	float getAnimationPercentage();
	void timerSetValue();
	void setAnimationPercentage(float AnimationPercentage);
	void onButtonClicked();
	void onStateButtonClicked();
	void onDataReceived(QJsonDocument Data);
	void onConnected();
	void onDisconnected();
	void onConnectionFailed();
};