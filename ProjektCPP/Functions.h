#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include "Organism.h"
#include "Animal.h"
#include "World.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Human.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Plant.h"
#include "Grass.h"
#include "Sow.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "Hogweed.h"

using namespace std;

enum SIZE
{
	HEIGHT = 20,
	WIDTH = 20
};

enum ANIMALS_STRENGTH
{
	HUMAN_STRENGTH = 5,
	WOLF_STRENGTH = 9,
	SHEEP_STRENGTH = 4,
	FOX_STRENGTH = 3,
	TURTLE_STRENGTH = 2,
	ANTELOPE_STRENGTH = 4
};

enum PLANT_STRENGTH
{
	GRASS_STRENGTH = 0,
	SOWTHISTLE_STRENGTH = 0,
	GUARANA_STRENGTH = 0,
	BELLADONNA_STRENGTH = 99,
	HOGWEED_STRENGTH = 10
};

enum ANIMALS_INITIATIVE
{
	HUMAN_INITIATIVE = 4,
	WOLF_INITIATIVE = 5,
	SHEEP_INITIATIVE = 4,
	FOX_INITIATIVE = 7,
	TURTLE_INITIATIVE = 1,
	ANTELOPE_INITIATIVE = 4
};

enum KEYBOARD
{
	ARROW_UP = 72,
	ARROW_LEFT = 75,
	ARROW_RIGHT = 77,
	ARROW_DOWN = 80,
	P_KEY = 112
};