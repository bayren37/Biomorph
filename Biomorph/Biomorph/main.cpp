#pragma once
#include "MyWindow.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ui::MyWindow w;
    w.show();

    return a.exec();
}
