#pragma once
#include "Functions.h"

class Animal:public Organism
{
public:
	Animal();
	Animal(int y, int x);
	~Animal();
	void action(Organism*** map, string& comment) override;
	void collision(Organism*** map, int pY, int pX, int nY, int nX, string& comment) override;
	void changeMove() override;
	int getMoved() override;
	void setMoved() override;
	void increaseAge() override;
	int getStrength() override;
	int getInitiative() override;
	void setY(int newY) override;
	void setX(int newX) override;
	void addStrength(int s) override;
	int getAge() override;
	string getName() override;
};

