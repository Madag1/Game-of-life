#pragma once
#include "Functions.h"

class Turtle :public Animal
{
public:
	Turtle(int y, int x);
	~Turtle();
	void action(Organism*** map, string& comment) override;
	void drawing() override;
	void collision(Organism*** map, int pY, int pX, int nY, int nX, string& comment) override;
	void breeading(Organism*** map, int pY, int pX, string& comment) override;
};

