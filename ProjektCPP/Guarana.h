#pragma once
#include "Functions.h"

class Guarana :public Plant
{
public:
	Guarana(int y, int x);
	~Guarana();
	void drawing() override;
	void collision(Organism*** map, int pY, int pX, int nY, int nX, string& comment) override;
	void action(Organism*** map, string& comment) override;

};

