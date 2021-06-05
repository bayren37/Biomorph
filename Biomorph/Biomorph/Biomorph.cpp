#pragma once

#include "Biomorph.h"

namespace bm {

    const double Biomorph::MUTANT_RATIO = 0.15;

	Biomorph::Biomorph()	
	{
		for (auto& gene : genes_)
			gene = global::rndi(9);

        color_.r = global::rndi(255);
        color_.g = global::rndi(255);
        color_.b = global::rndi(255);
        
        genes_[9] = global::rndi(3);        
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

		child->color_.r = 0.5 * (this->colors().r + mate.colors().r);
		child->color_.g = 0.5 * (this->colors().g + mate.colors().g);
		child->color_.b = 0.5 * (this->colors().b + mate.colors().b);

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