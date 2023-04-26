#pragma once
#include "Functions.h"

class Human :public Animal
{
protected:
	int extraStrength;
	int cooldown;
public:
	Human(int y, int x);
	~Human();
	void action(Organism*** map, string& comment) override;
	void drawing() override;
	void breeading(Organism*** map, int pY, int pX, string& comment) override;
	void ability();
	int getExtraStrength();
	void setExtraStrength(int p, int c);
	int getCooldown();
};

