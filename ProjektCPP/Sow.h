#pragma once
#include "Functions.h"
class Sow :public Plant
{
public:
	Sow(int y, int x);
	~Sow();
	void drawing() override;
	void action(Organism*** map, string& comment) override;
};

