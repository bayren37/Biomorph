#pragma once
#include "Segment.h"

namespace bm {
	
	Segment::Segment()
	{
		if (!cache_.empty())
		{
			x1_ = cache_[0];
			x2_ = cache_[1];
			y1_ = cache_[2];
			y2_ = cache_[3];
			
			return;
		}

		const int var = std::pow(2, 10);
		x1_.resize(var);
		x2_.resize(var);
		y1_.resize(var);
		y2_.resize(var);

		for (int i = 0; i < var; ++i)
		{
			x1_[i] = 0;
			x2_[i] = 0;
			y1_[i] = 0;
			y2_[i] = 0;
		}

	}

	void Segment::initialize()
	{
		for (int i = 0; i <= index_; i++)
			x1_[i] = x2_[i] = y1_[i] = y2_[i] = 0;

		cache_.push_back(x1_);
		cache_.push_back(x2_);
		cache_.push_back(y1_);
		cache_.push_back(y2_);
		index_ = 0;
	}

	void Segment::add(int x1, int x2, int y1, int y2)
	{
		this->x1_[index_] = x1;
		this->x2_[index_] = x2;
		this->y1_[index_] = y1;
		this->y2_[index_] = y2;
		index_ += 1;
	}
	pii Segment::dim()
	{
		xMax_ = *std::max_element(x2_.begin(), x2_.end());
		xMin_ = *std::min_element(x2_.begin(), x2_.end());
		yMax_ = *std::max_element(y2_.begin(), y2_.end());
		yMin_ = *std::min_element(y2_.begin(), y2_.end());

		return { xMax_ - xMin_, yMax_ - yMin_ };
	}

	void Segment::transfrom(unsigned int size, pii pos)
	{
		auto dimension = dim();
		auto width = dimension.first;
		auto height = dimension.second;
		auto maxSize = std::max(width, height);

		auto tSize = size - 6;
		unsigned int adj = 0;
		tSize > maxSize ? adj = 1 : adj = maxSize / tSize;

		auto mid = tSize / 2;
		auto xmin = this->xMin_ / adj;
		auto xmax = this->xMax_ / adj;
		auto ymin = this->yMin_ / adj;
		auto ymax = this->yMax_ / adj;

		auto w = xmax - xmin;
		auto h = ymax - ymin;

		auto x = pos.first - xmin - (w / 2) - 1;
		auto y = pos.second - ymin - (h / 2) - 1;

	}


}
