#include "Functions.h"

Antelope::Antelope(int y, int x)
{
	strength = ANTELOPE_STRENGTH;
	age = 0;
	initiative = ANTELOPE_INITIATIVE;
	posY = y;
	posX = x;
	moved = 0;
	name = "Antelope";
}

void Antelope::action(Organism*** map, string& comment)
{
	int flag = 0;

	int newX = posX;
	int newY = posY;

	while (flag == 0)
	{
		int pom = rand() % 4;

		if (pom == 0 && posY + 2 < HEIGHT)
		{
			flag = 1;
			newY += 2;
		}
		else if (pom == 1 && posY - 2 >= 0)
		{
			flag = 1;
			newY -= 2;
		}
		else if (pom == 2 && posX + 2 < WIDTH)
		{
			flag = 1;
			newX += 2;
		}
		else if (pom == 3 && posX - 2 >= 0)
		{
			flag = 1;
			newX -= 2;
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

	changeMove();
}

void Antelope::collision(Organism*** map, int pY, int pX, int nY, int nX, string& comment)
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

			int escape = rand() % 2;

			if (escape == 0)
			{
				comment += "Antelope escaped attacked from " + map[pY][pX]->getName();
				map[pY][pX] = tmp;
				map[pY][pX]->setY(pY);
				map[pY][pX]->setX(pX);
			}
			else
			{
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
}

void Antelope::breeading(Organism*** map, int pY, int pX, string& comment)
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

			map[newY][newX] = new Antelope(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		else if (pom % 4 == 1 && posY - 1 >= 0 && map[posY - 1][posX] == NULL)
		{
			flag = 1;
			newY -= 1;

			map[newY][newX] = new Antelope(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		else if (pom % 4 == 2 && posX + 1 < WIDTH && map[posY][posX + 1] == NULL)
		{
			flag = 1;
			newX += 1;

			map[newY][newX] = new Antelope(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		else if (pom == 3 && posX - 1 >= 0 && map[posY][posX - 1] == NULL)
		{
			flag = 1;
			newX -= 1;

			map[newY][newX] = new Antelope(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		pom++;
	}
}


void Antelope::drawing()
{
	cout << "a";
}

Antelope::~Antelope() {};
