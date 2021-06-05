#pragma once
#include "BiomorphWidget.h"
#include "Biomorph.h"

#include <QPainter>

namespace bm {

	BiomorphWidget::BiomorphWidget(QWidget* parent) : QPushButton(parent)
	{
		biomorph_ = std::make_shared<Biomorph>();
		initialize();

		setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
		setStyleSheet("QPushButton{ background-color: rgba(0, 0, 0, 100); border: 1px solid black;}");
	}

	void BiomorphWidget::nextGeneration(std::shared_ptr<Biomorph> mate)
	{
		biomorph_ = biomorph_->makeChild(*mate);
		initialize();
	}

	std::shared_ptr<Biomorph> BiomorphWidget::biomorph()
	{
		return biomorph_;
	}

	void BiomorphWidget::initialize()
	{
		auto genes = biomorph_->genes();
		order_ = genes[9];
		dx_[3] = genes[1];
		dx_[4] = genes[2];
		dx_[5] = genes[3];
		dx_[1] = -dx_[3];
		dx_[0] = -dx_[4];
		dx_[2] = 0;
		dx_[6] = 0;
		dx_[7] = -dx_[5];
		dy_[2] = genes[4];
		dy_[3] = genes[5];
		dy_[4] = genes[6];
		dy_[5] = genes[7];
		dy_[6] = genes[8];
		dy_[0] = dy_[4];
		dy_[1] = dy_[3];
		dy_[7] = dy_[5];

		repaint();
	}

	void BiomorphWidget::draw(int originX, int originY, QPainter* painter)
	{
		tree(originX, originY, order_, 2, painter);
	}

	void BiomorphWidget::tree(int x, int y, int order, int direction, QPainter* painter)
	{
		if (direction < 0)
			direction += 8;

		if (direction > 7)
			direction -= 8;

		int xto = x + order * dx_[direction];
		int yto = y - order * dy_[direction];

		painter->drawLine(x, y, xto, yto);

		if (order > 0)
		{
			tree(xto, yto, --order, --direction, painter);
			tree(xto, yto, --order, ++direction, painter);
		}
	}

	void BiomorphWidget::paintEvent(QPaintEvent* event)
	{
		auto painter = new QPainter;
		painter->begin(this);

		painter->setPen(QPen(QColor(biomorph_->colors().r, biomorph_->colors().g, biomorph_->colors().b), 2));
		draw(width()/2, 2*height()/3, painter);
		painter->end();

		__super::paintEvent(event);
		delete painter;
	}
}