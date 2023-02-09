#include "../../include/StyleSheet/StyleSheet.h"
QString GlobalStyle::InputWidget = "QWidget#InputWidget {background-color: #FFFFFF; }";

QString GlobalStyle::Title_1 = "QLabel#Title_1 {font-size: AUTO_5_PR; font-weight: bold;}";
QString GlobalStyle::Title_2 = "QLabel#Title_2 {font-size: AUTO_3_PR; font-weight: bold;}";
QString GlobalStyle::Text = "QLabel#Text {color:#666666;font-size: AUTO_2_PR;}";
QString GlobalStyle::Notice = "QLabel#Notice {font-size: AUTO_2_PR; color: red;}";
QString GlobalStyle::InputEdit = "QTextEdit#InputEdit {background-color: #EEEEEE;font-size: AUTO_2_PR; border-radius:4px}";
QString GlobalStyle::Button = "QPushButton#Button {font-size: AUTO_2_PR;}";
QString GlobalStyle::Button_Plus = "QPushButton#Button_Plus {font-size: 15px;}";
QString GlobalStyle::Button_Minus = "QPushButton#Button_Minus {font-size: 15px;}";
QString GlobalStyle::ScrollBar = "QScrollBar {background-color: #FFFFFF; width: 10px; border-radius: 5px;}";

QString GlobalStyle::getAllNormalStyle() {
	return Title_1 + Title_2 + Text + Notice + InputEdit + Button + Button_Plus + Button_Minus + ScrollBar;
}
QString GlobalStyle::QSSExtensionAUTOPR(QString QSS, QWidget* widget) {
	while (true) {
		if (QSS.contains("AUTO_") && QSS.contains("_PR")) {
			int Index_b = QSS.indexOf("AUTO_");
			int Index_e = QSS.indexOf("_PR");
			QString pr = QSS.mid(Index_b + 5, Index_e - Index_b - 5);
			QSS.replace("AUTO_" + pr + "_PR", QString::number((int)(pr.toFloat() * widget->height() / 100)) + "px");
		}
		else {
			break;
		}
	}
	return QSS;
}