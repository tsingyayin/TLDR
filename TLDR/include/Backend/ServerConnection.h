#pragma once
#include "../ginclude.h"

class ServerConnection :public QObject {
	Q_OBJECT;
signals:
	void serverConnected();
	void serverConnectionFailed();
	void serverDisconnected();
	void DataReceived(QJsonDocument);
private:
	QTcpSocket* Socket;
	QTimer* Timer;
	QString Buffer;
public:
	ServerConnection(QObject* parent  = Q_NULLPTR);
	~ServerConnection();
	void tryConnection();
	bool isConnected();
private:
	void connectToServer();
	void disconnectFromServer();
private slots:
	void onServerConnected();
	void onServerConnectionFailed();
	void displayError(QAbstractSocket::SocketError);
public slots:
	QString errorString();
	void receiveData();
	void sendData(QJsonDocument Data);
};