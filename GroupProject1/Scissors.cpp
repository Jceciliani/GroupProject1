#include "Scissors.h"

Scissors::Scissors()
{
	this->type = SCISSORS;
	setStrength(DEFAULT);
}

Scissors::Scissors(int strength)
{
	this->type = SCISSORS;
	setStrength(strength);
}

bool Scissors::fight(Tool*)
{
	return false;
}


Scissors::~Scissors() { }
