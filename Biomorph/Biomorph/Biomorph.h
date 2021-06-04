#pragma once
#include "Define.h"

namespace bm {

	class Biomorph
	{
	public:
		Biomorph();
		~Biomorph() = default;
		std::shared_ptr<Biomorph> makeChild(Biomorph& mate);
		const vi& genes();
		const Color& colors();
		const bool Biomorph::mutant();

	private:
		vi genes_ = vi(10);
		Color color_ = { 0,0,0 };

		static const double MUTANT_RATIO;
		//Rect rect_;
		//std::vector<Segment> segments_;
	};
}

