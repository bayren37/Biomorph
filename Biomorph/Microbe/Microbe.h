#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Microbe.h"

class Microbe : public QMainWindow
{
    Q_OBJECT

public:
    Microbe(QWidget *parent = Q_NULLPTR);

private:
    Ui::MicrobeClass ui;
};
