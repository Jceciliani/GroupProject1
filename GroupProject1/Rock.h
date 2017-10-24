/***************
#ifndef ROCK_H
#define ROCK_H
#include "Tool.h"

const int DEFAULT = 1;
const char ROCK = 'r';

class Rock : public Tool
{
	public:
		//CONSTRUCTOR
		Rock();
		Rock(int);

		//FUNCTIONS
		bool fight(Tool);

		//DESCTRUCTOR
		~Rock();
};

#endif // !ROCK_H
*********************/

#ifndef RPSGame_HPP
#define RPSGame_HPP
#include <cstdio> // Reference: https://www.tutorialspoint.com/c_standard_library/stdio_h.htm
#include "tool.h"

class RPSGame 
{
protected:
	Tool *human;
	Tool *computer;
	Tool* getTool();
	Tool* getComputer();
	int human_wins;
	int computer_wins;
	int ties;
	int customRockStrength();
	int customPaperStrength();
	int customScissorsStrength();
	void checkFight();
	void chooseStrength();


public:
	RPSGame();
	int playRPS();
	void operator=(const RPSGame &other);
	RPSGame(const RPSGame &other);
	~RPSGame();


};
#endif
