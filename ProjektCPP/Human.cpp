#include "Functions.h"

Human::Human(int y, int x)
{
	cooldown = 0;
	extraStrength = 0;
	strength = HUMAN_STRENGTH;
	age = 0;
	initiative = HUMAN_INITIATIVE;
	posY = y;
	posX = x;
	moved = 0;
	name = "Human";
}

void Human::action(Organism*** map, string& comment)
{
	ability();

	if (this->getStrength() + this->getCooldown() > this->getStrength())
	{
		int pom = getExtraStrength() - 1;

		if (pom < 0)
			pom = 0;

		int pom2 = getCooldown() - 1;

		setExtraStrength(pom, pom2);

		if (pom2 <= 5)
			cout << "Ability is on cooldown. Turns remaining: " << this->getCooldown() << endl;
		else
			cout << "Human strength is: " << this->getStrength() << endl;
	}

	int flag = 0;

	int newX = posX;
	int newY = posY;

	while (flag == 0)
	{
		char pom = _getch();

		if (pom == ARROW_DOWN && posY + 1 < HEIGHT)
		{
			flag = 1;
			newY += 1;
		}
		else if (pom == ARROW_UP && posY - 1 >= 0)
		{
			flag = 1;
			newY -= 1;
		}
		else if (pom == ARROW_RIGHT && posX + 1 < WIDTH)
		{
			flag = 1;
			newX += 1;
		}
		else if (pom == ARROW_LEFT && posX - 1 >= 0)
		{
			flag = 1;
			newX -= 1;
		}
		else if (pom == P_KEY)
		{
			if (this->getStrength() + this->getCooldown() > this->getStrength())
			{
				comment += "Ability already in use or on cooldown \n";
				flag = 0;
			}
			else
			{
				flag = 1;
				setExtraStrength(HUMAN_STRENGTH, HUMAN_STRENGTH+6);
				comment += "Special ability activated \n";
			}
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

void Human::breeading(Organism*** map, int pX, int pY, string& comment){}

int Human::getCooldown()
{
	return cooldown;
}

int Human::getExtraStrength()
{
	return extraStrength;
}

void Human::setExtraStrength(int p, int c)
{
	extraStrength = p;
	cooldown = c;
}

void Human::ability()
{
	strength = this->getStrength() + extraStrength;
}

void Human::drawing()
{
	cout << "M";
}

Human::~Human() {};

