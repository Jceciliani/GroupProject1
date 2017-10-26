#ifndef PAPER_H
#define PAPER_H
#include "Tool.h"




class Paper : public Tool
{
	public:
		//CONSTRUCTORS
		Paper();
		Paper(int);

		//FUNCTIONS
		int fight(Tool*);

		//DESTRUCTORS
		~Paper();
};

#endif // !PAPER_H

