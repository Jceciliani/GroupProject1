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


