#pragma once
#include "stdafx.h"

typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;

namespace bm {

	struct Rect
	{
		int left_;
		int top_;
		int right_;
		int bottom_;
	};

	struct Color
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
	};

	struct Gene
	{
		int number_;
		pii level_;
		pii ln_;
	};

	struct Genenome
	{
		Genenome() {
			for (auto& level : levels_)
				level = std::make_pair(-9, 9);
		}
		vpii levels_ = vpii(9);
	};
}