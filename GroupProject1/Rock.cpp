#include "Rock.h"

Rock::Rock()
{
	this->type = ROCK;
	setStrength(DEFAULT);
}

Rock::Rock(int strength)
{
	this->type = ROCK;
	setStrength(strength);
	
}

bool Rock::fight(Tool*)
{
	return false;
}

Rock::~Rock() { }
