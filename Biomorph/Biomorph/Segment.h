#pragma once
#include "stdafx.h"

namespace bm {

	class Segment
	{
	public:
		Segment();
		~Segment() = default;
		
		void add(int x1, int x2, int y1, int y2);

	private:
		std::vector<int> x1;
		std::vector<int> x2;
		std::vector<int> y1;
		std::vector<int> y2;
		
		int index;
		int xMax;
		int xMin;
		int yMax;
		int yMin;

	}
}

