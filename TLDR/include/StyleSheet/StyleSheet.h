#pragma once
#include "../ginclude.h"

class GlobalStyle :public QObject
{
	Q_OBJECT
public:
	static QString InputWidget;
	static QString StateWidget;
	static QString Title_1;
	static QString Title_2;
	static QString Text;
	static QString Notice;
	static QString InputEdit;
	static QString Button;
	static QString Button_Plus;
	static QString Button_Minus;
	static QString ScrollBar;
	static QString GrayCover;
	static QString getAllNormalStyle();
	static QString QSSExtensionAUTOPR(QString QSS, QWidget* widget);
};