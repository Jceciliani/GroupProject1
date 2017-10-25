#ifndef HelperFunctions_HPP
#define HelperFunctions_HPP

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

namespace HelperFunctions
{
	void clearScreen();
	int getValidInt(const std::string, int min = 0, int max = 0);
	char getValidChar(const std::string, std::vector<char>);
	bool getYesNo(const std::string);
	bool openInputFile(std::ifstream&);
	bool openOutputFile(std::ofstream&);
	//TODO Update with other DataTypes / Options... Update to Namespace
}

#endif
