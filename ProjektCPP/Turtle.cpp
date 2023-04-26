#include "Functions.h"

Turtle::Turtle(int y, int x)
{
	strength = TURTLE_STRENGTH;
	age = 0;
	initiative = TURTLE_INITIATIVE;
	posY = y;
	posX = x;
	moved = 0;
	name = "Turtle";
}

void Turtle::action(Organism*** map, string& comment)
{
	int flag = 0;
	int pom, newX, newY;

	pom = rand() % 4;

	if (pom >= 2)
		comment += "Turtle hasn't moved \n";
	if (pom == 1)
	{
		while (flag == 0)
		{
			newX = posX;
			newY = posY;
			pom = rand() % 4;

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
		if (map[newY][newX] != NULL)
			map[newY][newX]->collision(map, posY, posX, newY, newX, comment);
		else
		{
			map[newY][newX] = this;
			map[posY][posX] = NULL;
			posY = newY;
			posX = newX;
		}
	}

	changeMove();
}

void Turtle::collision(Organism*** map, int pY, int pX, int nY, int nX, string& comment)
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
			if (attackerStrength < 5)
			{
				comment += "Turtle reflected attack of " + map[pY][pX]->getName() + "\n";
				map[pY][pX] = tmp;
				map[pY][pX]->setY(pY);
				map[pY][pX]->setX(pX);

			}
			else
			{
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
}

void Turtle::breeading(Organism*** map, int pY, int pX, string& comment)
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

			map[newY][newX] = new Turtle(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		else if (pom % 4 == 1 && posY - 1 >= 0 && map[posY - 1][posX] == NULL)
		{
			flag = 1;
			newY -= 1;

			map[newY][newX] = new Turtle(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		else if (pom % 4 == 2 && posX + 1 < WIDTH && map[posY][posX + 1] == NULL)
		{
			flag = 1;
			newX += 1;

			map[newY][newX] = new Turtle(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		else if (pom == 3 && posX - 1 >= 0 && map[posY][posX - 1] == NULL)
		{
			flag = 1;
			newX -= 1;

			map[newY][newX] = new Turtle(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		pom++;
	}
}


void Turtle::drawing()
{
	cout << "t";
}

Turtle::~Turtle() {};

