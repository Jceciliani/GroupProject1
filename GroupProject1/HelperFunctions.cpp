/************************************************************
** Author: Devon Aleshire
** Date: 10-22-2017
** Description: Class implementation file for HelperFunctions
*************************************************************/
#include "HelperFunctions.hpp"

namespace HelperFunctions {

	//Prototypes
	bool checkIsDigit(std::string);
	bool checkIsAlpha(std::string userInput);

	/*************************************************************
	** Description: Gets valid integer input from user
	**************************************************************/
	//TODO Simplify nested if's
	int getValidInt(const std::string prompt, int min, int max) {

		std::string userInput = "";
		bool isValid = false;
		int num = 0;

		do {
			std::cout << prompt << ": ";
			std::getline(std::cin, userInput);

			if (userInput.empty()) {
				std::cout << "\nValue cannot be empty.\n\n";
			}
			else {
				bool isNum = checkIsDigit(userInput);
				if (isNum)
				{
					num = std::stoi(userInput, nullptr);
					if ((max > 0 && min > 0) && (num > max || num < min))
					{
						std::cout << "\nPlease enter a valid number between " << min;
						std::cout << " and " << max << ".\n\n";
					}
					else
					{
						isValid = true;
					}
				}
				else
				{
					std::cout << "\nPlease enter only a single number value.\n\n";
				}
			}

		} while (!isValid);
		return num;
	}

	char getValidChar(const std::string prompt, std::vector<char> validChars)
	{
		std::string userInput = "";
		bool isValid = false;
		char character = '!';

		do {
			std::cout << prompt << ": ";
			std::getline(std::cin, userInput);

			if (userInput.empty()) {
				std::cout << "\nValue cannot be empty.\n\n";
			}
			else if(userInput.length() > 1) {
				std::cout << "\nPlease input only a single character.\n\n";
			}
			else {
				bool isAlpha = checkIsAlpha(userInput);
				if (isAlpha)
				{
					character = tolower(userInput[0]);
					for (size_t i = 0; i < validChars.size(); i++) {
						if (character == validChars[i]) {
							isValid = true;
							break;
						}
					}
				}
				else
				{
					std::cout << "Please input only alpha characters.\n\n";
				}
			}

		} while (!isValid);
		return character;
	}

	/*************************************************************
	** Description: Checks each input value to ensure it is value
	betweeen 0-9.
	**************************************************************/
	bool checkIsAlpha(std::string userInput) {
		int numChar = userInput.length();
		bool isAlpha = true;

		for (int i = 0; i < numChar; i++) {
			char index = userInput[i];
			if (!isalpha(index)) {
				isAlpha = false;
				break;
			}
		}

		return isAlpha;
	}

	/*************************************************************
	** Description: Checks each input value to ensure it is value
	betweeen 0-9.
	**************************************************************/
	bool checkIsDigit(std::string userInput) {
		int numChar = userInput.length();
		bool isNum = true;

		for (int i = 0; i < numChar; i++) {
			char index = userInput[i];
			if (!isdigit(index)) {
				isNum = false;
				break;
			}
		}

		return isNum;
	}

	/*************************************************************
	** Description: Prompts user for yes or no input
	**************************************************************/
	bool getYesNo(const std::string prompt) {
		int selection = getValidInt(prompt, 1, 2);
		return selection == 1;
	}

	/*************************************************************
	** Description: Opens File for ifstream
	**************************************************************/
	bool openInputFile(std::ifstream &ifs)
	{
		std::string fileName = "";
		std::cout << "Please enter file Name to open: ";
		std::getline(std::cin, fileName);

		ifs.open(fileName);
		//ifs.open("file_fun.txt");

		if (!ifs) {
			std::cout << "Sorry, the file was inaccessible" << std::endl << std::endl;
			return false;
		}
		std::cout << std::endl << "File \"" << fileName << "\" has been opened for reading." 
				                                                          << std::endl << std::endl;
		return true;
	}

	/*************************************************************
	** Description: Opens File for ofstream
	**************************************************************/
	bool openOutputFile(std::ofstream &ofs)
	{
		std::string outputFile;

		std::cout << "Please enter file name to write to: ";
		std::cin >> outputFile;
		ofs.open(outputFile);
		if (!ofs) {
			std::cout << "There was an error opening the outout file for writing." << std::endl;
			return false;
		}
		std::cout << std::endl << "File \"" << outputFile << "\" has been opened for writing." << std::endl;
		return true;
	}

	/*************************************************************
	** Description: Clears the console screen
	**************************************************************/
	void clearScreen()
	{
		system("clear");
		//system("cls"); => Use for Windows
	}
}




