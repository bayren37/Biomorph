#include "Microbe.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Microbe w;
    w.show();
    return a.exec();
}
