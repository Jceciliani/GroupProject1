/**************************************************
#ifndef RPSGAME_H
#define RPSGAME_H
#include "Tool.h"

const int TOOL_SIZE = 2;

class RPSGame
{
	private:
		Tool* human;
		Tool* computer;

		int human_wins;
		int computer_wins;
		int ties;
	public:
		RPSGame();
		~RPSGame();
};


#endif // !RPSGAME_H
************************************************/

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


