#pragma once
#include "MyWindow.h"
#include "BiomorphWidget.h"

#include <QLayout>
#include <QWidget>
#include <QPainter>

namespace ui {

    MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent)
    {
        setCentralWidget(new CentralWidget(this));
    }

    CentralWidget::CentralWidget(QWidget* parent) : QWidget(parent)
    {
        auto layout = new QHBoxLayout;
        auto top = new QHBoxLayout;
        {

        }


        auto bottom = new QHBoxLayout;
        {
            auto grid = new QGridLayout();

            for (auto i = 0; i < 3; ++i)
            {
                for (auto j = 0; j < 3; ++j)
                {
                    auto biomorphWidget = new bm::BiomorphWidget();
					BiomorphWidgets_->addButton(biomorphWidget, i + j);
                    connect(biomorphWidget, abstractbu)
					grid->addWidget(biomorphWidget, i, j);
                }
            }
            bottom->addLayout(grid);
        }

        layout->addLayout(bottom);
        setLayout(layout);
    }
}
