#pragma execution_character_set("utf-8")
#include <QApplication>
#include "include/UI/MainWindow.h"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	int FontID = QFontDatabase::addApplicationFont(":/main/resource/HarmonyOS_Sans_SC_Regular.ttf");
	app.setFont(QFontDatabase::applicationFontFamilies(FontID).at(0));
	MainWindow* window = new MainWindow();
	window->show();
	return app.exec();
}