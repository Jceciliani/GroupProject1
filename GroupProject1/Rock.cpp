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

int Rock::fight(Tool* tool)
{
	int fightOutcome = 0;
	int strength = this->getStrength();
	if (tool->getType() == SCISSORS)
	{
		strength *= 2;
	}
	else if(tool->getType() == PAPER)
	{
		strength *= .5;
	}
	
	Tool::DisplayBattleStrengths(strength, tool->getStrength());
	fightOutcome = Tool::compare(strength, tool->getStrength());
	
	return fightOutcome;
}

Rock::~Rock() { }
