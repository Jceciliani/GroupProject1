#include "Paper.h"

Paper::Paper()
{
	this->type = PAPER;
	setStrength(DEFAULT);
}

Paper::Paper(int strength)
{
	this->type = PAPER;
	setStrength(strength);
}

bool Paper::fight(Tool*)
{
	return false;
}


Paper::~Paper() { }
