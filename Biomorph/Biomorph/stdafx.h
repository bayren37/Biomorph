#pragma once

#include <QWidget>
#include <QString>

#include <vector>
#include <algorithm>
#include <random>
#include <memory>

namespace global {

	static std::random_device rd;
	static std::mt19937 gen(rd());

	static int rndi(int i)
	{
		std::uniform_int_distribution<> distr(0, i);
		return distr(global::gen);
	}

	static int rndi(int lower, int upper)
	{
		std::uniform_int_distribution<> distr(lower, upper);
		return distr(global::gen);
	}

	static bool tossCoin()
	{
		return rndi(1) == 0;
	}

	static double rndd(double d)
	{
		std::uniform_int_distribution<> distr(0.0, d);
		return distr(global::gen);
	}
}