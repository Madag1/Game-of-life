#pragma once
#include "Functions.h"

class Fox :public Animal
{
public:
	Fox(int y, int x);
	~Fox();
	void action(Organism*** map, string& comment) override;
	void drawing() override;
	void breeading(Organism*** map, int pY, int pX, string& comment) override;

};

