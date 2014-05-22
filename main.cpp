#include "mainkakula.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainKakula w;
    w.show();
    
    return a.exec();
}
