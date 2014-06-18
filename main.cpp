#include "mainkakula.h"
#include "meter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainKakula w;
    w.show();

    //QVUMeter meter;
    //meter.show();
    
    return a.exec();
}
