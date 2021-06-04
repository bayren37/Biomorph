#pragma once

#include "Biomorph.h"

namespace bm {

    const double Biomorph::MUTANT_RATIO = 0.1;

	Biomorph::Biomorph()	
	{
		for (auto& gene : genes_)
			gene = global::rndi(5);

		genes_[9] = global::rndi(5);
	}

    std::shared_ptr<Biomorph> Biomorph::makeChild(Biomorph& mate)
    {
        auto child = std::make_shared<Biomorph>();

        for (int i = 0; i < 10; ++i)
        {
            if (global::tossCoin())
            {
                child->genes_[i] = this->genes_[i];
            }
            else
            {
                child->genes_[i] = mate.genes_[i];

            }

            if (mutant())
                child->genes_[i] += global::rndi(-2, 2);
        }

        return child;
    }

    const vi& Biomorph::genes()
    {
        return genes_;
    }

    const Color& Biomorph::colors()
    {
        return color_;
    }

    const bool Biomorph::mutant()
    {
        std::uniform_real_distribution<> distr(0.0, 1.0);
        return distr(global::gen) < Biomorph::MUTANT_RATIO;
    }
}