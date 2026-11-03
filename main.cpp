
#include "mainwindow.h"

#include <QApplication>
#include "MyWindow.h"

#include <QtMath>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QVector<QPointF> nabor;
    for(int i=1; i<720; i++){
        double x = i * 3.1415926535 / 180;
        double y = std::sin(x);
        nabor.append(QPointF(x,y));
    }
    MyMainWindow w(nabor);
	w.show();
	return a.exec();
}
