#include "Functions.h"

Hogweed::Hogweed(int y, int x)
{
	strength = HOGWEED_STRENGTH;
	age = 0;
	initiative = 0;
	posY = y;
	posX = x;
	moved = 0;
	name = "Hogweed";
}

void Hogweed::drawing()
{
	cout << "^";
}

void Hogweed::action(Organism*** map, string& comment)
{
	int pom = rand() % 9;

	if (pom == 1)
	{
		int newY = posY;
		int newX = posX;

		int pom = rand() % 4;
		int flag2 = pom + 3;
		int flag = 0;

		while (pom <= flag2 && flag == 0)
		{
			if (pom % 4 == 0 && posY + 1 < HEIGHT && map[posY + 1][posX] == NULL)
			{
				flag = 1;
				newY += 1;

				map[newY][newX] = new Hogweed(newY, newX);
				comment += "Plant " + map[posY][posX]->getName() + " sow" + "\n";
			}
			else if (pom % 4 == 1 && posY - 1 >= 0 && map[posY - 1][posX] == NULL)
			{
				flag = 1;
				newY -= 1;

				map[newY][newX] = new Hogweed(newY, newX);
				comment += "Plant " + map[posY][posX]->getName() + " sow" + "\n";
			}
			else if (pom % 4 == 2 && posX + 1 < WIDTH && map[posY][posX + 1] == NULL)
			{
				flag = 1;
				newX += 1;

				map[newY][newX] = new Hogweed(newY, newX);
				comment += "Plant " + map[posY][posX]->getName() + " sow" + "\n";
			}
			else if (pom == 3 && posX - 1 >= 0 && map[posY][posX - 1] == NULL)
			{
				flag = 1;
				newX -= 1;

				map[newY][newX] = new Hogweed(newY, newX);
				comment += "Plant " + map[posY][posX]->getName() + " sow" + "\n";
			}
			pom++;
		}
	}

	changeMove();
}

void Hogweed::collision(Organism*** map, int pY, int pX, int nY, int nX, string& comment)
{
	if (map[posY + 1][posX] != NULL)
	{
		if (map[posY + 1][posX]->getInitiative() > 0)
		{
			comment += map[posY + 1][posX]->getName() + " was to close to Hogweed and is dead :/ \n";
			map[posY + 1][posX] = NULL;
		}
	}
	if (map[posY - 1][posX] != NULL)
	{
		if (map[posY - 1][posX]->getInitiative() > 0)
		{
			comment += map[posY - 1][posX]->getName() + " was to close to Hogweed and is dead :/ \n";
			map[posY - 1][posX] = NULL;
		}
	}
	if (map[posY][posX + 1] != NULL)
	{
		if (map[posY][posX + 1]->getInitiative() > 0)
		{
			comment += map[posY][posX + 1]->getName() + " was to close to Hogweed and is dead :/ \n";
			map[posY][posX + 1] = NULL;
		}

	}
	if (map[posY][posX - 1] != NULL)
	{
		if (map[posY][posX - 1]->getInitiative() > 0)
		{
			comment += map[posY][posX - 1]->getName() + " was to close to Hogweed and is dead :/ \n";
			map[posY][posX - 1] = NULL;
		}

	}

	if (map[nY][nX] != NULL)
	{
		Organism* tmp = map[pY][pX];

		int attackerStrength = map[pY][pX]->getStrength();
		int defenderStrength = map[nY][nX]->getStrength();

		if (attackerStrength >= defenderStrength)
		{
			comment += map[pY][pX]->getName() + " ate " + map[nY][nX]->getName() + " and got +3 strength \n";
			map[nY][nX] = NULL;
			map[pY][pX]->setY(nY);
			map[pY][pX]->setX(nX);
			map[nY][nX] = tmp;
			map[nY][nX]->addStrength(3);
			map[pY][pX] = NULL;
		}
		else
		{
			comment += map[nY][nX]->getName() + " killed " + map[pY][pX]->getName() + "\n";
			map[pY][pX] = NULL;
		}
	}
}

Hogweed::~Hogweed() {};


