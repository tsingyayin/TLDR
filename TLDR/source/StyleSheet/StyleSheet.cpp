#include "../../include/StyleSheet/StyleSheet.h"
QString GlobalStyle::InputWidget = "QWidget#InputWidget {background-color: #00FFFFFF; }\
QFrame#NumInputLine{border-radius:22px;background-color:#FFFFFF}";
QString GlobalStyle::StateWidget = "QFrame#StateWidget {background-color: #77FFFFFF; }";
QString GlobalStyle::Title_1 = "QLabel#Title_1 {font-size: AUTO_5_PR; font-weight: bold;}";
QString GlobalStyle::Title_2 = "QLabel#Title_2 {font-size: AUTO_4_PR; font-weight: bold;background-color:#FFFFFF;border-radius:20px;}";
QString GlobalStyle::Text = "QLabel {color:#000000;font-size: AUTO_3_PR;}";
QString GlobalStyle::Notice = "QLabel#Notice {font-size: AUTO_2_PR; color: red;}";
QString GlobalStyle::InputEdit = "QTextEdit {background-color: #EEEEEE;font-size: AUTO_2_PR; border-radius:20px}\
QLineEdit{border:0px solid white}";
QString GlobalStyle::Button = "QPushButton#Button\
 {color:#FFFFFF;font-size: AUTO_3_PR;border-radius:20px;background-color:qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 #FF5D93, stop:1 #A25DFF);}\
QPushButton#Button:hover\
{background-color: #EEEEEE;color: #FF7F27;}\
QPushButton#Button:pressed\
{background-color: #DDDDDD;color: #FF7F27;}\
QPushButton{font-size: AUTO_3_PR;border-radius:15px;border:0px solid white;background-color:#FFFFFF}";
QString GlobalStyle::Button_Plus = "";
QString GlobalStyle::Button_Minus = "\
QPushButton#Button_Minus,QPushButton#Button_Plus {\
    font-size: AUTO_2_PR;\
    border-radius:22px;\
    border:0px solid #FF7F27;\
    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 #FF5D93, stop:1 #A25DFF);\
    color:#FFFFFF;\
}\
QPushButton#Button_Minus:hover,QPushButton#Button_Plus:hover\
{background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 #DE5810, stop:1 #844CD0);}\
QPushButton#Button_Minus:pressed,QPushButton#Button_Plus:hover\
{background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 #DE5810, stop:1 #844CD0);}";
QString GlobalStyle::ScrollBar = "\
                QScrollBar:horizontal{\
                    background-color:#FFFFFF;\
                    margin:0px, 0px, 0px, 0px;\
                    border-radius:20px;\
                    padding-top:0px;\
                    padding-bottom:0px;\
                }\
                QScrollBar::handle:horizontal{\
                    background-color:qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 #FF5D93, stop:1 #A25DFF);\
                    border-radius:20px;\
                    width:10px;\
                }\
                QScrollBar::handle:horizontal:hover{\
                    background-color:qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 #DE5810, stop:1 #844CD0);\
                    border-radius:20px;\
                    width:10px;\
                }\
                QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal{\
                    background-color:#00FF7F27;\
                    height:1px;\
                }\
                QScrollBar::add-line:horizontal{\
                    height:0px;\
                    width:0px;\
                    subcontrol-position:bottom;\
                }\
                QScrollBar::sub-line:horizontal{\
                    height:0px;\
                    width:0px;\
                    subcontrol-position:top;\
                }\
\
                QSlider:horizontal{\
                    background-color:#00FFFFFF;\
                    margin:0px, 0px, 0px, 0px;\
                    border-radius:20px;\
                }\
                QSlider::handle:horizontal{\
                    background-color:qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 #DE5810, stop:1 #844CD0);\
                    border-radius:5px;\
                    width:50px;\
                }\
                QSlider::add-page:horizontal,QSlider::sub-page:horizontal{\
                    height:20px;\
                }";
QString GlobalStyle::GrayCover = "QLabel#GrayCover {background-color: #AA000000;}";

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