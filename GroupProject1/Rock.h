
#ifndef ROCK_H
#define ROCK_H
#include "Tool.h"

const char ROCK = 'r';

class Rock : public Tool
{
	public:
		//CONSTRUCTOR
		Rock();
		Rock(int);

		//FUNCTIONS
		bool fight(Tool*);

		//DESCTRUCTOR
		~Rock();
};

#endif // !ROCK_H


