#include "../../include/Backend/ServerConnection.h"

ServerConnection::ServerConnection(QObject* parent):QObject(parent) {
	Socket = new QTcpSocket(this);
	Buffer = QByteArray();
	Timer = new QTimer(this);
	Timer->setInterval(10000);
	//Socket->setProxy(QNetworkProxy::NoProxy);
	connect(Socket, SIGNAL(readyRead()), this, SLOT(receiveData()));
	connect(Socket, SIGNAL(connected()), this, SLOT(onServerConnected()));
	connect(Socket, SIGNAL(disconnected()), this, SIGNAL(serverDisconnected()));
	//监听错误并打印
	qRegisterMetaType<QAbstractSocket::SocketError>("QAbstractSocket::SocketError");
	connect(Socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
	
	Timer->setSingleShot(true);
	this->tryConnection();
}

ServerConnection::~ServerConnection() {
	this->disconnectFromServer();
}

void ServerConnection::tryConnection() {
	//this->disconnectFromServer();
	connect(Timer, SIGNAL(timeout()), this, SLOT(onServerConnectionFailed()), Qt::UniqueConnection);
	Timer->start();
	this->connectToServer();
}
bool ServerConnection::isConnected() {
	return Socket->state() == QAbstractSocket::ConnectedState;
}
QString ServerConnection::errorString() {
	return Socket->errorString();
}
void ServerConnection::onServerConnected() {
	disconnect(Timer, SIGNAL(timeout()), this, SLOT(onServerConnectionFailed()));
	Timer->stop();
	qDebug() << "Connected";
	emit serverConnected();
}
void ServerConnection::onServerConnectionFailed() {
	disconnect(Timer, SIGNAL(timeout()), this, SLOT(onServerConnectionFailed()));
	Timer->stop();
	emit serverConnectionFailed();
	qDebug() << "Connection Failed";
	qDebug() << Socket->proxy().applicationProxy().type();
	qDebug() << Socket->errorString();
}
void ServerConnection::displayError(QAbstractSocket::SocketError e){
	qDebug() << Socket->proxy().applicationProxy().type();
	qDebug() << Socket->errorString();
}
void ServerConnection::connectToServer() {
	Socket->connectToHost(QHostAddress("175.27.187.91"), 14123);
}
void ServerConnection::disconnectFromServer() {
	qDebug() << "Disconnect from Server";
	Socket->disconnectFromHost();
	emit serverDisconnected();
}
void ServerConnection::sendData(QJsonDocument Data) {
	qDebug() << Data;
	Socket->write(Data.toJson()+"\r\n\r\n");
}
void ServerConnection::receiveData() {
	QString Data = Socket->readAll();
	Buffer.append(Data);
	if (Buffer.contains("\r\n\r\n")) {
		QStringList DataList = Buffer.split("\r\n\r\n");
		for (int i = 0; i < DataList.length() - 1; i++) {
			if (DataList[i].isEmpty()) {
				continue;
			}
			QJsonDocument Data = QJsonDocument::fromJson(DataList[i].toUtf8());
			emit DataReceived(Data);
		}
		Buffer = DataList.last();
	}
}