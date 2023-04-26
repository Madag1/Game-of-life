#pragma once
#include "Functions.h"

class Belladonna :public Plant
{
public:
	Belladonna(int y, int x);
	~Belladonna();
	void drawing() override;
	void action(Organism*** map, string& comment) override;
};

