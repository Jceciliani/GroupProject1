/******************************************************************************
** Authors: Devon Aleshire, Joshua Ceciliani, Todd Irlbeck, Nikita Mattingly,
** and Edward Pietryk
** Date: 10/22/2017
** Description: Tool.h is the Tool class header file.
** The Tool class has member variables including Strength and Type, and a 
** member function called SetStrength(int) that sets the strength for the Tool.
******************************************************************************/

#ifndef TOOL_H
#define TOOL_H
#include <iostream>

const int DEFAULT = 1;
const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

class Tool
{
        protected:
                int strength;
                char type;

        public:
                Tool();
                Tool(int, char);
                virtual ~Tool();
                void setStrength(const int);
                int getStrength() const;
                void setType(const char);
				char getType() const;
				static int compare(int a, int b);
				virtual int fight(Tool*);
				void DisplayBattleStrengths(int a, int b);
};

#endif // !TOOL_H
