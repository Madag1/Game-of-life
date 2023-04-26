#include "Functions.h"

Plant::Plant(){}

Plant::Plant(int y, int x){}

Plant::~Plant(){}

string Plant::getName()
{
	return name;
}

int Plant::getAge()
{
	return age;
}

void Plant::changeMove()
{
	if (moved == 0)
		moved = 1;
	else
		moved = 0;
}

int Plant::getMoved()
{
	return moved;
}

void Plant::setMoved()
{
	moved = 0;
}

void Plant::increaseAge()
{
	age++;
}

int Plant::getStrength()
{
	return strength;
}

int Plant::getInitiative()
{
	return initiative;
}

void Plant::setY(int newY)
{
	posY = newY;
}

void Plant::setX(int newX)
{
	posX = newX;
}

void Plant::addStrength(int s)
{
	strength += s;
}

void Plant::breeading(Organism*** map, int pX, int pY, string& comment){}

void Plant::action(Organism*** map, string& comment)
{
	int pom = rand() % 3;

	if (pom == 1)
	{
		int newY = posY;
		int newX = posX;

		int pom = rand() % 4;
		int flag2 = pom + 3;
		int flag = 0;

		while (pom <= flag2 && flag == 0)
		{
			if (pom % 4 == 0 && posY + 1 < HEIGHT && map[posX + 1][posX] == NULL)
			{
				flag = 1;
				newY += 1;

				map[newY][newX] = map[posY][posX];
				comment += "Plant " + map[posY][posX]->getName() + " sow" + "\n";
			}
			else if (pom % 4 == 1 && posY - 1 >= 0 && map[posX - 1][posX] == NULL)
			{
				flag = 1;
				newY -= 1;

				map[newY][newX] = map[posY][posX];
				comment += "Plant " + map[posY][posX]->getName() + " sow" + "\n";
			}
			else if (pom % 4 == 2 && posX + 1 < WIDTH && map[posX][posX + 1] == NULL)
			{
				flag = 1;
				newX += 1;

				map[newY][newX] = map[posY][posX];
				comment += "Plant " + map[posY][posX]->getName() + " sow" + "\n";
			}
			else if (pom == 3 && posX - 1 >= 0 && map[posX][posX - 1] == NULL)
			{
				flag = 1;
				newX -= 1;

				map[newY][newX] = map[posY][posX];
				comment += "Plant " + map[posY][posX]->getName() + " sow" + "\n";
			}
			pom++;
		}
	}

	changeMove();
}

void Plant::collision(Organism*** map, int pY, int pX, int nY, int nX, string& comment)
{
	if (map[nY][nX] != NULL)
	{
		Organism* tmp = map[pY][pX];

		int attackerStrength = map[pY][pX]->getStrength();
		int defenderStrength = map[nY][nX]->getStrength();

		if (attackerStrength >= defenderStrength)
		{
			comment += map[pY][pX]->getName() + " ate " + map[nY][nX]->getName() + "\n";
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