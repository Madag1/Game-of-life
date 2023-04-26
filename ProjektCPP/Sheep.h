#pragma once
#include "Functions.h"

class Sheep :public Animal
{
public:
	Sheep(int y, int x);
	~Sheep();
	void drawing() override;
	void breeading(Organism*** map, int pY, int pX, string& comment) override;
};

