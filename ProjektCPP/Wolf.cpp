#include "Wolf.h"
#include <iostream>

using namespace std;

Wolf::Wolf(int y, int x) 
{
	strength = WOLF_STRENGTH;
	age = 0;
	initiative = WOLF_INITIATIVE;
	posY = y;
	posX = x;
	moved = 0;
	name = "Wolf";
}

void Wolf::breeading(Organism*** map, int pY, int pX, string& comment)
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

			map[newY][newX] = new Wolf(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		else if (pom % 4 == 1 && posY - 1 >= 0 && map[posY - 1][posX] == NULL)
		{
			flag = 1;
			newY -= 1;

			map[newY][newX] = new Wolf(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		else if (pom % 4 == 2 && posX + 1 < WIDTH && map[posY][posX + 1] == NULL)
		{
			flag = 1;
			newX += 1;

			map[newY][newX] = new Wolf(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		else if (pom == 3 && posX - 1 >= 0 && map[posY][posX - 1] == NULL)
		{
			flag = 1;
			newX -= 1;

			map[newY][newX] = new Wolf(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		pom++;
	}
}

void Wolf::drawing()
{
	cout << "w";
}

Wolf::~Wolf() {};

