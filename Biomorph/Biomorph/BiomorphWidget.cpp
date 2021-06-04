#pragma once
#include "BiomorphWidget.h"

#include <QPainter>

namespace bm {

	BiomorphWidget::BiomorphWidget(QWidget* parent) : QPushButton(parent)
	{
		initialize();
		setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
		setStyleSheet("QPushButton{background:transparent;}");
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
	}

	void BiomorphWidget::draw(int i, int j, QPainter* painter)
	{
		tree(i / 2, j, order_, 2, painter);
	}

	void BiomorphWidget::tree(int i, int j, int k, int l, QPainter* painter)
	{
		if (l < 0)
			l += 8;

		if (l >= 8)
			l -= 8;

		int i1 = i + k * dx_[l];
		int j1 = j - k * dy_[l];

		painter->drawLine(i, j, i1, j1);

		if (k > 0)
		{
			tree(i1, j1, k - 1, l - 1, painter);
			tree(i1, j1, k - 1, l + 1, painter);
		}
	}

	void BiomorphWidget::paintEvent(QPaintEvent* event)
	{
		auto painter = new QPainter;
		painter->begin(this);
		painter->setPen(QPen(Qt::black, 1));
		draw(width(), height() / 2, painter);
		painter->end();

		__super::paintEvent(event);
		delete painter;
	}
}