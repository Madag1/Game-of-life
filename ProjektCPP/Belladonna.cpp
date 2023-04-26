#include "Functions.h"

Belladonna::Belladonna(int y, int x)
{
	strength = BELLADONNA_STRENGTH;
	age = 0;
	initiative = 0;
	posY = y;
	posX = x;
	moved = 0;
	name = "Belladonna";
}

void Belladonna::drawing()
{
	cout << "B";
}

void Belladonna::action(Organism*** map, string& comment)
{
	int pom = rand() % 27;

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

				map[newY][newX] = new Belladonna(newY, newX);
				comment += "Plant " + map[posY][posX]->getName() + " sow" + "\n";
			}
			else if (pom % 4 == 1 && posY - 1 >= 0 && map[posY - 1][posX] == NULL)
			{
				flag = 1;
				newY -= 1;

				map[newY][newX] = new Belladonna(newY, newX);
				comment += "Plant " + map[posY][posX]->getName() + " sow" + "\n";
			}
			else if (pom % 4 == 2 && posX + 1 < WIDTH && map[posY][posX + 1] == NULL)
			{
				flag = 1;
				newX += 1;

				map[newY][newX] = new Belladonna(newY, newX);
				comment += "Plant " + map[posY][posX]->getName() + " sow" + "\n";
			}
			else if (pom == 3 && posX - 1 >= 0 && map[posY][posX - 1] == NULL)
			{
				flag = 1;
				newX -= 1;

				map[newY][newX] = new Belladonna(newY, newX);
				comment += "Plant " + map[posY][posX]->getName() + " sow" + "\n";
			}
			pom++;
		}
	}

	changeMove();
}

Belladonna::~Belladonna() {};


