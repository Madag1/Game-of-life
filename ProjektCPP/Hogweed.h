#pragma once
#include "Plant.h"

class Hogweed :public Plant
{
public:
	Hogweed(int y, int x);
	~Hogweed();
	void drawing() override;
	void action(Organism*** map, string& comment) override;
	void collision(Organism*** map, int pY, int pX, int nY, int nX, string& comment) override;

};


