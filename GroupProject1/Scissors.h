#ifndef SCISSORS_H
#define SCISSORS_H
#include "Tool.h"

const int DEFAULT = 1;
const char SCISSORS = 's';

class Scissors : public Tool
{
	public:
		//CONSTRUCTOR
		Scissors();
		Scissors(int);

		//FUNCTIONS
		bool fight(Tool);

		//DESTRUCTOR
		~Scissors();
};

#endif // !SCISSORS_H

