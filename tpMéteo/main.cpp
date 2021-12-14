#include "tpMteo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tpMteo w;
    w.show();
    return a.exec();
}
