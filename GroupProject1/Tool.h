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

const int DEFAULT = 1;

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
				virtual bool fight(Tool*);
};

#endif // !TOOL_H
