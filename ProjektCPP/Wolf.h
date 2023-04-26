#pragma once
#include "Functions.h"

class Wolf :public Animal
{
public:
	Wolf(int y, int x);
	~Wolf();
	void drawing() override;
	void breeading(Organism*** map, int pY, int pX, string& comment) override;
};

