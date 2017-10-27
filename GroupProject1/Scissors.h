#ifndef SCISSORS_H
#define SCISSORS_H
#include "Tool.h"



class Scissors : public Tool
{
	public:
		//CONSTRUCTOR
		Scissors();
		Scissors(int);
		
		//Functions
		int fight(Tool*);

		//DESTRUCTOR
		~Scissors();
};

#endif // !SCISSORS_H

