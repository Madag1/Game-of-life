#pragma once
#include "Functions.h"

class Plant :public Organism
{
public:
	Plant();
	Plant(int y, int x);
	~Plant();
	void action(Organism*** map, string& comment) override;
	void collision(Organism*** map, int pY, int pX, int nY, int nX, string& comment) override;
	string getName() override;
	int getAge() override;
	void changeMove() override;
	int getMoved() override;
	void setMoved() override;
	void increaseAge() override;
	int getStrength() override;
	int getInitiative() override;
	void setY(int newY) override;
	void setX(int newX) override;
	void addStrength(int s) override;
	void breeading(Organism*** map,int pX, int pY, string& comment) override;

};

