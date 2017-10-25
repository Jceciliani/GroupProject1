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
#include "Menu.hpp"
#include "HelperFunctions.hpp"

//enum Tools {PAPER = 1, ROCK, SCISSORS};
const int MAX_STRENGTH = 10;
const int MIN_STRENGTH = 1;
const char EXIT = 'e';

class RPSGame 
{
protected:
	Menu menu;
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
