#ifndef PAPER_H
#define PAPER_H
#include "Tool.h"

const int DEFAULT = 1;
const char PAPER = 'p';

class Paper : public Tool
{
	public:
		//CONSTRUCTORS
		Paper();
		Paper(int);

		//FUNCTIONS
		bool fight(Tool);

		//DESTRUCTORS
		~Paper();
};

#endif // !PAPER_H

