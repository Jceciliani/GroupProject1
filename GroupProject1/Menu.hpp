#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "HelperFunctions.hpp"

//TODO Make more robust and extensible, Y or N / DataTypes / etc
class Menu
{
	//MEMBER VARIABLES
	private:
		std::string title;
		std::vector<std::string> options;
		std::map<int, std::vector<std::string>> subMenus;
		static std::map<int, std::string> valueOptions;
			
	//MEMBER FUNCTIONS
	public:
		//CONSTRUCTORS/DESTRUCTOR
		Menu();
		Menu(std::string, std::vector<std::string>);
		~Menu();

		//SETTERS
		void setTitle(std::string);
		void AddMenuOption(std::string);
		void AddValueOption(int, const std::string);
		void AddSubMenu(int, int, std::string);
		void UpdateValueOption(int, const std::string);

		//GETTERS
		std::string getTitle();
		int getNumOptions();
		std::string getValueOption(int);
		void displaySubMenu(int);
		void displayTitle();

		//CLASS FUNCTIONS
		void displayMenu();
		void yesNo(bool);
		void clearOptions();
};

#endif // !MENU_HPP

