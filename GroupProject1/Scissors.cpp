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

Scissors::~Scissors() { }
