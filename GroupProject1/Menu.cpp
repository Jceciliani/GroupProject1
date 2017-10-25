/************************************************************
** Author: Devon Aleshire
** Date: 10-22-2017
** Description: Class implementation file for reusable Menu
*************************************************************/
#include "Menu.hpp"

/*************************************************************
** Description: Default Constructor
**************************************************************/
Menu::Menu(){ }

/*************************************************************
** Description: Constructor to set title and options
**************************************************************/
Menu::Menu(std::string title, std::vector<std::string> options)
{
	this->title = title;
	this->options = options;
}

//SETTERS
/*************************************************************
** Description: Set Title of Menu
**************************************************************/
void Menu::setTitle(std::string title) {
	this->title = title;
}

/*************************************************************
** Description: Add a new single menu option
**************************************************************/
void Menu::AddMenuOption(std::string option)
{
	options.push_back(option);
}

/*************************************************************
** Description: Add a new single value option
** ---Create enum to access each option---
**************************************************************/
void Menu::AddValueOption(int key, const std::string option)
{
	if (valueOptions.size() == 0) {
		valueOptions.insert(std::pair<int, std::string>(key, option));
	}
	else if (valueOptions.find(key) == valueOptions.end()) {
		valueOptions.insert(std::pair<int, std::string>(key, option));
	}

}

void Menu::AddSubMenu(int subMenuName, int index, std::string menuInfo)
{
	//subMenus[subMenuName] = menuInfo;
}

/*************************************************************
** Description: Add a new single value option
** ---Create enum to access each option---
**************************************************************/
void Menu::UpdateValueOption(int key, const std::string option)
{
	if (valueOptions.find(key) != valueOptions.end()) {
		valueOptions[key] = option;
	}

}

//GETTERS
/*************************************************************
** Description: Returns current title
**************************************************************/
std::string Menu::getTitle() {
	return title;
}

/*************************************************************
** Description: Returns current number of options
**************************************************************/
int Menu::getNumOptions() {
	return options.size();
}

/*************************************************************
** Description: Returns single value menu option
**************************************************************/
std::string Menu::getValueOption(int key) {
	if (valueOptions.find(key) != valueOptions.end()) {
		return valueOptions[key];
	}

	return "";//TODO Update design	
}

void Menu::displaySubMenu(int subMenu)
{
	std::vector<std::string> temp = subMenus[subMenu];

	for (size_t i = 0; i < temp.size(); i++)
	{
		std::cout << temp[i] << std::endl;
	}
}

/*************************************************************
** Description: Display the Menu title and options
**************************************************************/
void Menu::displayMenu()
{
	std::cout << title << std::endl;
	for (std::size_t i = 0; i < options.size(); i++) {
		std::cout << i + 1 << ") " << options[i] << std::endl;
	}
	std::cout << std::endl;
}

void Menu::displayTitle() {
	std::cout << title << std::endl;
}

/*************************************************************
** Description: Clears all current options from menu
**************************************************************/
void Menu::clearOptions() {
	options.clear();
}

/*************************************************************
** Description: Display the Menu title and options
**************************************************************/
void Menu::yesNo(bool displayTitle)
{
	if (displayTitle) {
		std::cout << title << std::endl;
	}
	std::cout << "1) Yes" << std::endl;
	std::cout << "2) No" << std::endl;
}

/*************************************************************
** Description: Static variable
**************************************************************/
std::map<int, std::string> Menu::valueOptions;

/*************************************************************
** Description: Destructor
**************************************************************/
Menu::~Menu() {}
