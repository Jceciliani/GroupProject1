/******************************************************************************
** Authors: Devon Aleshire, Joshua Ceciliani, Todd Irlbeck, Nikita Mattingly,
** and Edward Pietryk
** Date: 10/22/2017
** Description: RPSGame.cpp is source file for RPSGame class. It allows the
** user to set tool strengths, pick tools while allowing the computer to pick
** its own tools, choose a winner, and play the game. It also contains the
** constructor, copy constructor, and destructor. 
******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RPSGame.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
//Default Constructor
RPSGame::RPSGame() 
{
	human_wins = 0;
	computer_wins = 0;
	ties = 0;

	//Seeding rand()
	srand(std::time(0));

	//Using raw string literal to make ascii art appear
	//Reference: https://stackoverflow.com/questions/37765925/ascii-art-in-c
	menu.setTitle(
		R"(
	 ___         _     ___                      ___     _                   _  
	| _ \___  __| |__ | _ \__ _ _ __  ___ _ _  / __| __(_)______ ___ _ _ __| | 
	|   / _ \/ _| / / |  _/ _` | '_ \/ -_) '_| \__ \/ _| (_-<_-</ _ \ '_(_-<_| 
	|_|_\___/\__|_\_\ |_| \__,_| .__/\___|_|   |___/\__|_/__/__/\___/_| /__(_) 
	                           |_|                                             
	 )" +
		std::string("~*~*~*~*~*~*~*~*~*~*WELCOME TO ROCK, PAPER, SCISSORS!~*~*~*~*~*~*~*~*~*~*~\n\n\n") +
		std::string("-----------------------------DIRECTIONS-----------------------------------\n") +
		std::string("You will be playing rock, paper, and scissors against the computer!\n\n") +
		std::string("Before we begin, would you like to select the different strengths for the tools?\n"));
}

/*********************************************************************
** Function: void chooseStrength()
** Description: User can choose custom strengths
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Strengths are set
*********************************************************************/
void RPSGame::chooseStrength() 
{
	customRockStrength = 
		HelperFunctions::getValidInt("Enter an integer to set the strength for ROCK", MIN_STRENGTH, MAX_STRENGTH);
	customPaperStrength = 
		HelperFunctions::getValidInt("Enter an integer to set the strength for PAPER", MIN_STRENGTH, MAX_STRENGTH);
	customScissorsStrength = 
		HelperFunctions::getValidInt("Enter an integer to set the strength for SCISSORS", MIN_STRENGTH, MAX_STRENGTH);
}

/*********************************************************************
** Function: getTool()
** Description: Prompts the user to pick a tool
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Tool is picked
*********************************************************************/
Tool* RPSGame::getTool() 
{
	char selection;

	selection = HelperFunctions::getValidChar(
		"Select your tool: (r) Rock | (p) Paper | (s) Scissors | (e) EXIT\n\nSelection",
			VALID_CHARS
	);

	if (selection == ROCK) 
	{
		return new Rock(customRockStrength);
	}
	else if (selection == PAPER) 
	{
		return new Paper(customPaperStrength);
	}
	else if (selection == SCISSORS) 
	{
		return new Scissors(customScissorsStrength);
	}
	else if (selection == EXIT) 
	{
		return 0;
	}

}

/*********************************************************************
** Function: getComputer()
** Description: The computer chooses its own tool
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Computer tool is picked
*********************************************************************/
Tool* RPSGame::getComputer() 
{
	int x = rand() % 3 + 1; //Generates a random number btw 1 and 3
	if (x == 1) 
	{
		cout << "Computer chooses Rock!" << endl;
		return new Rock(customRockStrength);
	}
	else if (x == 2) 
	{
		cout << "Computer Chooses Paper!" << endl;
		return new Paper(customPaperStrength);
	}
	else if (x == 3) {
		cout << "Computer chooses Scissors!" << endl;
		return new Scissors(customScissorsStrength);
	}
	return 0;
}

/*********************************************************************
** Function: checkFight()
** Description: Compares the human and AI to see who wins
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Winner is chosen
*********************************************************************/
void RPSGame::checkFight() 
{
	int action = human->fight(computer);
	cout << endl;
	if (action == WIN) 
	{
		cout << "Good job Human! You win!" << endl;
		human_wins++;
	}
	else if (action == LOSE) 
	{
		cout << "Computer wins!" << endl;
		computer_wins++;
	}
	else 
	{
		cout << "Tie game." << endl;
		ties++;
	}

	displayStats();
}

/*********************************************************************
** Function: playRPS()
** Description: This function will play the game
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Game is played
*********************************************************************/
int RPSGame::playRPS() 
{
	//Menu
	menu.displayMenu();

	//Set Initial Strength Values
	int strengthSelection = HelperFunctions::getYesNo("Please enter(1) Yes OR(2) No");
	if (strengthSelection == 1)
	{
		chooseStrength();
	}
	else {
		strengthRandomizer();
	}
	
	//Game loop
	do {
		human = getTool();
		if (human == NULL) 
		{
			return 0;
		}
		computer = getComputer();
		checkFight();

		delete human;
		delete computer;
	}

	while (1);
}

void RPSGame::displayStats() {
	cout << endl << "<<**CURRENT GAME**>>" << endl;
	cout << "Human wins: " << human_wins << endl;
	cout << "Computer wins: " << computer_wins << endl;
	cout << "Ties: " << ties << endl << endl;
}

void RPSGame::strengthRandomizer()
{
	customRockStrength     = rand() % 10 + 1;
	customPaperStrength    = rand() % 10 + 1;
	customScissorsStrength = rand() % 10 + 1;
}

//Assignment Overload
void RPSGame::operator=(const RPSGame &other) 
{
	human_wins = other.human_wins;
	computer_wins = other.computer_wins;
	ties = other.ties;

	if (other.human != NULL) 
	{
		delete other.human;
	}
	if (other.computer != NULL) 
	{
		delete other.computer;
	}
}

//Copy Constructor, reference: https://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm
RPSGame::RPSGame(const RPSGame &other) 
{
	if (other.human == NULL) 
	{
		human = NULL;
	}
	else if (other.human->getType() == 'r') 
	{
		human = new Rock;
		human->setStrength(other.human->getStrength());
	}
	else if (other.human->getType() == 's') {
		human = new Scissors;
		human->setStrength(other.human->getStrength());
	}
	else if (other.human->getType() == 'p') {
		human = new Paper;
		human->setStrength(other.human->getStrength());
	}
}

// This is the destructor...
RPSGame::~RPSGame() 
{
	if (human != NULL) 
	{

		delete human;
	}
	if (computer != NULL) 
	{

		delete computer;
	}
}
