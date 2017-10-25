/******************************************************************************
** Authors: Devon Aleshire, Joshua Ceciliani, Todd Irlbeck, Nikita Mattingly,
** and Edward Pietryk
** Date: 10/22/2017
** Description: Tool.cpp is the Tool class definition file.
** The Tool class has member variables including Strength and Type, and a 
** member function called SetStrength(int) that sets the strength for the Tool.
**
** References:
** TODO
******************************************************************************/

#include "Tool.h"

/******************************************************************************
*                               Tool::Tool()
* Description: Default constructor
******************************************************************************/
Tool::Tool()
{
    strength = -1; //Strength initialized to -1 to indicate need for setting
    type = 63;     //Type is initialized to '?' to indicate need for setting
}

/******************************************************************************
*                               Tool::Tool()
* Description: Overload constructor
* Parameters: 
*    int, tool strength
*    char, tool type
* Return type: 
*    None
******************************************************************************/
Tool::Tool(int strength, char type)
{
    this->strength = strength;
    this->type = type;
}

/******************************************************************************
*                               Tool::~Tool()
* Description: Destructor
******************************************************************************/
Tool::~Tool()
{
}

/******************************************************************************
*                             Tool::setStrength()
* Description: Sets the strength for tool
* Parameters: 
*    int, tool strength
* Return type: 
*    None
******************************************************************************/
void Tool::setStrength(const int strength)
{
    this->strength = strength;
}

/******************************************************************************
*                             Tool::getStrength()
* Description: Gets the strength that tool is set to
* Parameters: 
*    None
* Return type: 
*    int, tool strength
******************************************************************************/
int Tool::getStrength() const
{
    return strength;
}

/******************************************************************************
*                             Tool::setType()
* Description: Sets the type for tool
* Parameters: 
*    char, tool type
* Return type: 
*    None
******************************************************************************/
void Tool::setType(const char type)
{
    this->type = type;
}

/******************************************************************************
*                             Tool::getStrength()
* Description: Gets the tool type
* Parameters: 
*    None
* Return type: 
*    char, tool type
******************************************************************************/
char Tool::getType() const
{
    return type;
}

bool Tool::fight(Tool *)
{
	return false;
}
