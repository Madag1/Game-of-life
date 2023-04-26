#include "Functions.h"

Animal::Animal() {}

Animal::Animal(int y, int x) {}

void Animal::changeMove()
{
	if (moved == 0)
		moved = 1;
	else
		moved = 0;
}

void Animal::setMoved()
{
	moved = 0;
}

int Animal::getAge()
{
	return age;
}

int Animal::getMoved()
{
	return moved;
}

int Animal::getStrength()
{
	return strength;
}

int Animal::getInitiative()
{
	return initiative;
}

void Animal::setY(int newY)
{
	posY = newY;
}

void Animal::setX(int newX)
{
	posX = newX;
}

void Animal::addStrength(int s)
{
	strength += s;
}

void Animal::action(Organism*** map, string& comment)
{
	int flag = 0;

	int newX = posX;
	int newY = posY;

	while (flag == 0)
	{
		int pom = rand() % 4;

		if (pom == 0 && posY + 1 < HEIGHT)
		{
			flag = 1;
			newY += 1;
		}
		else if (pom == 1 && posY - 1 >= 0)
		{
			flag = 1;
			newY -= 1;
		}
		else if (pom == 2 && posX + 1 < WIDTH)
		{
			flag = 1;
			newX += 1;
		}
		else if (pom == 3 && posX - 1 >= 0)
		{
			flag = 1;
			newX -= 1;
		}
	}
	if(map[newY][newX] != NULL)
		map[newY][newX]->collision(map,posY,posX,newY,newX, comment);
	else
	{
		map[newY][newX] = this;
		map[posY][posX] = NULL;
		posY = newY;
		posX = newX;
	}
	
	changeMove();
}

void Animal::increaseAge()
{
	age++;
}

string Animal::getName()
{
	return name;
}

void Animal::collision(Organism*** map, int pY, int pX, int nY, int nX, string& comment)
{
	if (map[nY][nX] != NULL)
	{
		if (map[pY][pX]->getName() == map[nY][nX]->getName())
		{
			map[pY][pX]->breeading(map, pY, pX, comment);
		}
		else
		{
			Organism* tmp = map[pY][pX];

			int attackerStrength = map[pY][pX]->getStrength();
			int defenderStrength = map[nY][nX]->getStrength();

			if (attackerStrength >= defenderStrength)
			{
				comment += map[pY][pX]->getName() + " killed " + map[nY][nX]->getName() + "\n";
				map[nY][nX] = NULL;
				map[pY][pX]->setY(nY);
				map[pY][pX]->setX(nX);
				map[nY][nX] = tmp;
				map[pY][pX] = NULL;
			}
			else
			{
				comment += map[nY][nX]->getName() + " killed " + map[pY][pX]->getName() + "\n";
				map[pY][pX] = NULL;
			}
		}
	}
}

Animal::~Animal() {}