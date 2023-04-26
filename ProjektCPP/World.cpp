#include "Functions.h"

using namespace std;

World::World(int height, int width)
{
	turn = 0;
	map = new Organism** [height];
	comment = "";

	for (int i = 0; i < height; ++i)
	{
		map[i] = new Organism*[width];
	}

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			map[i][j] = NULL;
		}
	}

	map[2][5] = new Human(2, 5);
	map[4][6] = new Wolf(4, 6);
	//map[1][1] = new Wolf(1, 1);
	map[9][9] = new Sheep(9, 9);
	map[0][9] = new Sheep(0, 9);
	map[9][0] = new Fox(9, 0);
	map[10][10] = new Fox(10, 10);
	map[14][16] = new Turtle(14, 16);
	map[2][18] = new Turtle(2, 18);
	map[5][17] = new Antelope(5, 17);
	map[18][4] = new Antelope(18, 4);

	map[12][10] = new Grass(12, 10); //  +
	map[19][19] = new Sow(19, 19); //  @
	map[2][16] = new Guarana(2, 16); //  !
	map[9][17] = new Belladonna(9, 17); //  B
	//map[18][15] = new Hogweed(18, 15); //  ^

	drawWorld(map);

	while (true)
	{
		makeTurn(map);
		cout << "It is turn: " << turn << endl;
		coutComment(&comment);
		clearComment(&comment);
	}
}

int World::getTurn()
{
	return turn;
}

void World::setTurn(int& turn)
{
	turn++;
}

void World::coutComment(string* comment)
{
	cout << *comment;
}

void World::clearComment(string* comment)
{
	*comment = "";
}

void World::makeTurn(Organism*** map)
{
	turn++;

	int initiative[5] = {7,5,4,1,0};

	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			if (map[i][j] != NULL)
			{
				map[i][j]->setMoved();
				map[i][j]->increaseAge();
			}
		}
	}

	for (int m = 0; m < 5; ++m)
	{
		for (int i = 0; i < HEIGHT; ++i)
		{
			for (int j = 0; j < WIDTH; ++j)
			{
				if (map[i][j] != NULL && map[i][j]->getInitiative() == initiative[m])
				{
					if (map[i][j]->getMoved() == 0)
					{
						map[i][j]->action(map, comment);
					}
				}
			}
		}
	}

	//setTurn(turn);
	system("cls");
	drawWorld(map);

}

void World::drawWorld(Organism*** map)
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			if (map[i][j] != NULL)
				map[i][j]->drawing();
			else
				cout << ".";
		}
		cout << endl;
	}
}

World::~World()
{
	
}