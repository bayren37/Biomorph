#pragma once

#include "stdafx.h"
#include "Biomorph.h"
#include <qpushbutton.h>

namespace bm {

	class BiomorphWidget : public QPushButton
	{
		Q_OBJECT
	public:
		BiomorphWidget(QWidget* parent = nullptr);
		~BiomorphWidget() = default;

	private:
		void initialize();
		void draw(int i, int j, QPainter* painter);
		void tree(int i, int j, int k, int l, QPainter* painter);

	private:
		void paintEvent(QPaintEvent* event);

	private:
		std::shared_ptr<Biomorph> biomorph_ = std::make_shared<Biomorph>();

		int order_ = -1;
		vi dx_ = vi(8);
		vi dy_ = vi(8);
	};
}