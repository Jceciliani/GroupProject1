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
/******************************************************************************
** Authors: Devon Aleshire, Joshua Ceciliani, Todd Irlbeck, Nikita Mattingly,
** and Edward Pietryk
** Date: 10/22/2017
** Description: RPSGame.hpp is the header file.
******************************************************************************/
#ifndef RPSGame_H
#define RPSGame_H
#include <cstdio>
#include "Tool.h"

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
	int customRockStrength;
	int customPaperStrength;
	int customScissorsStrength;
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
