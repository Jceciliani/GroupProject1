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

int Scissors::fight(Tool* tool)
{
	int fightOutcome = 0;
	int strength = this->getStrength();
	
	if (tool->getType() == PAPER)
	{
		strength *= 2;
	}
	else if (tool->getType() == ROCK)
	{
		strength *= .5;
	}
	Tool::DisplayBattleStrengths(strength, tool->getStrength());
	fightOutcome = Tool::compare(strength, tool->getStrength());

	return fightOutcome;
}

Scissors::~Scissors() { }
