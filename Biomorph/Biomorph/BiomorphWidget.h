#pragma once

#include "stdafx.h"
#include <qpushbutton.h>

namespace bm {

	class Biomorph;

	class BiomorphWidget : public QPushButton
	{
		Q_OBJECT
	public:
		BiomorphWidget(QWidget* parent = nullptr);
		~BiomorphWidget() = default;

	public:
		std::shared_ptr<Biomorph> biomorph();
		void nextGeneration(std::shared_ptr<Biomorph> mate);

	private:
		void initialize();
		void draw(int i, int j, QPainter* painter);
		void tree(int i, int j, int k, int l, QPainter* painter);

	private:
		void paintEvent(QPaintEvent* event);

	private:
		std::shared_ptr<Biomorph> biomorph_;

		int order_ = -1;
		vi dx_ = vi(8);
		vi dy_ = vi(8);
	};
}