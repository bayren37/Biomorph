#pragma once
#include "MyWindow.h"
#include "BiomorphWidget.h"

#include <QLayout>
#include <QWidget>
#include <QPainter>
#include <QAbstractButton>

namespace ui {

    MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent)
    {
        setCentralWidget(new CentralWidget(this));
    }

    CentralWidget::CentralWidget(QWidget* parent) : QWidget(parent)
    {
        BiomorphWidgets_ = new QButtonGroup;
        connect(BiomorphWidgets_, &QButtonGroup::idClicked, this, &CentralWidget::buttonClicked);
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
					grid->addWidget(biomorphWidget, i, j);
                }
            }
            bottom->addLayout(grid);
        }

        layout->addLayout(bottom);
        setLayout(layout);
    }
    
    void CentralWidget::buttonClicked(int id)
    {
        auto button = BiomorphWidgets_->button(id);
        auto parent = dynamic_cast<bm::BiomorphWidget*>(button);

        if (parent == nullptr)
            return;

        for (auto& other : BiomorphWidgets_->buttons())
        {
            auto otherParent = dynamic_cast<bm::BiomorphWidget*>(other);
            otherParent->nextGeneration(parent->biomorph());
        }
    }
}
