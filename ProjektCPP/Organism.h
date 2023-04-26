#pragma once
#include "Functions.h"

using namespace std;

class Organism
{
protected:
	string name;
	int strength;
	int initiative;
	int posY;
	int posX;
	int age;
	int moved;
public:
	virtual void action(Organism*** map, string& comment)=0;
	virtual void drawing()=0;
	virtual void collision(Organism*** map, int pY, int pX, int nY, int nX, string& comment)=0;
	virtual void changeMove() = 0;
	virtual int getMoved() = 0;
	virtual void setMoved() = 0;
	virtual void increaseAge() = 0;
	virtual int getStrength() = 0;
	virtual void addStrength(int s) = 0;
	virtual int getInitiative() = 0;
	virtual void setY(int newY) = 0;
	virtual void setX(int newX) = 0;
	virtual string getName() = 0;
	virtual int getAge() = 0;
	virtual void breeading(Organism*** map,int pX, int pY, string& comment) = 0;
	Organism();
	Organism(int y, int x);
	~Organism();
};

