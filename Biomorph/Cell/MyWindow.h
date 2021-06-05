#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MyWindow.h"

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::MyWindowClass ui;
};
