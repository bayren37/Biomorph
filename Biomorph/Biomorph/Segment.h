#pragma once
#include "stdafx.h"
#include "Define.h"

namespace bm {

	class Segment
	{
	public:
		Segment();
		~Segment() = default;

		void initialize();
		void add(int x1, int x2, int y1, int y2);
		pii dim();
		void transfrom(unsigned int size, pii pos);


	private:
		vi x1_ = {};
		vi x2_ = {};
		vi y1_ = {};
		vi y2_ = {};

		int index_ = 0;
		int xMax_ = 0;
		int xMin_ = 0;
		int yMax_ = 0;
		int yMin_ = 0;

		vvi cache_;
	};
}

