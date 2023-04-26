#pragma once
#include "Functions.h"

class Grass:public Plant
{
public:
	Grass(int y, int x);
	~Grass();
	void drawing() override;
	void action(Organism*** map, string& comment) override;
};

