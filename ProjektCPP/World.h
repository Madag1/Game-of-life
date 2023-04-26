#pragma once
#include "Functions.h"

using namespace std;

class World
{
protected:
	string comment;
	int turn;
	Organism*** map;
public:
	World(int height, int width);
	~World();
	void makeTurn(Organism*** map);
	void drawWorld(Organism*** map);
	void coutComment(string* comment);
	void clearComment(string* comment);
	int getTurn();
	void setTurn(int& turn);
};

