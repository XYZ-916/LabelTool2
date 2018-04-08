#pragma execution_character_set("utf-8")
#include "labeltool.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QCoreApplication::addLibraryPath("./plugins");

	QApplication a(argc, argv);
	LabelTool w;
	w.show();
	return a.exec();
}
