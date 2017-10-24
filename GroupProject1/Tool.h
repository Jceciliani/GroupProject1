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

class Tool
{
        protected:
                int strength;
                char type;
        public:
                Tool();
                Tool(int, char);
                virtual ~Tool();
                virtual void setStrength(const int);
                virtual int getStrength() const;
                virtual void setType(const char);
                virtual char getType() const;
};

#endif // !TOOL_H
