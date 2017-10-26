
#ifndef ROCK_H
#define ROCK_H
#include "Tool.h"



class Rock : public Tool
{
	public:
		//CONSTRUCTOR
		Rock();
		Rock(int);

		//FUNCTIONS
		int fight(Tool*);

		//DESCTRUCTOR
		~Rock();
};

#endif // !ROCK_H


