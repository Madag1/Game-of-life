#include "Functions.h"


Fox::Fox(int y, int x)
{
	strength = FOX_STRENGTH;
	age = 0;
	initiative = FOX_INITIATIVE;
	posY = y;
	posX = x;
	moved = 0;
	name = "Fox";
}

void Fox::action(Organism*** map, string& comment)
{
	int flag = 0;
	int pom, newX, newY;

	while (flag == 0)
	{
		newX = posX;
		newY = posY;
		pom = rand() % 4;

		if (pom == 0 && posY + 1 < HEIGHT)
		{
			flag = 1;
			newY += 1;

			if(map[posY + 1][posX] != NULL)
			{
				if (map[posY + 1][posX]->getStrength() > strength)
					flag = 0;
			}
		}
		else if (pom == 1 && posY - 1 >= 0)
		{
			flag = 1;
			newY -= 1;

			if (map[posY - 1][posX] != NULL)
			{
				if (map[posY - 1][posX]->getStrength() > strength)
					flag = 0;
			}
		}
		else if (pom == 2 && posX + 1 < WIDTH)
		{
			flag = 1;
			newX += 1;

			if (map[posY][posX + 1] != NULL)
			{
				if (map[posY][posX + 1]->getStrength() > strength)
					flag = 0;
			}
		}
		else if (pom == 3 && posX - 1 >= 0)
		{
			flag = 1;
			newX -= 1;

			if (map[posY][posX - 1] != NULL)
			{
				if (map[posY][posX - 1]->getStrength() > strength)
					flag = 0;
			}
		}
	}
	if(map[newY][newX] != NULL)
		map[newY][newX]->collision(map,posY,posX,newY,newX,comment);
	else
	{
		map[newY][newX] = this;
		map[posY][posX] = NULL;
		posY = newY;
		posX = newX;
	}
	
	changeMove();
}

void Fox::breeading(Organism*** map, int pY, int pX, string& comment)
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

			map[newY][newX] = new Fox(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		else if (pom % 4 == 1 && posY - 1 >= 0 && map[posY - 1][posX] == NULL)
		{
			flag = 1;
			newY -= 1;

			map[newY][newX] = new Fox(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		else if (pom % 4 == 2 && posX + 1 < WIDTH && map[posY][posX + 1] == NULL)
		{
			flag = 1;
			newX += 1;

			map[newY][newX] = new Fox(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		else if (pom == 3 && posX - 1 >= 0 && map[posY][posX - 1] == NULL)
		{
			flag = 1;
			newX -= 1;

			map[newY][newX] = new Fox(newY, newX);
			comment += "Animal " + map[posY][posX]->getName() + " bread" + "\n";
		}
		pom++;
	}
}


void Fox::drawing()
{
	cout << "f";
}

Fox::~Fox() {};
