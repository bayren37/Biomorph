#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Biomorph.h"

class Biomorph : public QMainWindow
{
    Q_OBJECT

public:
    Biomorph(QWidget *parent = Q_NULLPTR);

private:
    Ui::BiomorphClass ui;
};
