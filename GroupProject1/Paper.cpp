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

int Paper::fight(Tool* tool)
{
	int fightOutcome = 0;
	int strength = this->getStrength();
	
	if (tool->getType() == ROCK)
	{
		strength *= 2;
	}
	else if (tool->getType() == SCISSORS)
	{
		strength *= .5;
	}
	Tool::DisplayBattleStrengths(strength, tool->getStrength());
	fightOutcome = Tool::compare(strength, tool->getStrength());

	return fightOutcome;
}


Paper::~Paper() { }
