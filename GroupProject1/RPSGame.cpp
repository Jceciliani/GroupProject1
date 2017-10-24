/***
#include "RPSGame.h"

RPSGame::RPSGame()
{
	human_wins = 0;
	computer_wins = 0;
	ties = 0;
}


RPSGame::~RPSGame()
{
}

*****/

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
#include "rock.h"
#include "paper.h"
#include "scissors.h"

using std::cin;
using std::cout;
using std::endl;

//Default Constructor
RPSGame::RPSGame() 
{
	human_wins = 0;
	computer_wins = 0;
	ties = 0;
	customRockStrength = 1;
	customScissorsStrength = 1;
	customPaperStrength = 1;
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
	cout << "Enter a integer to set the strength for ROCK: ";
	cin >> customRockStrength;
	cout << endl;
	cout << "Enter an integer to set the strength for PAPER: ";
	cin >> customPaperStrength;
	cout << endl;
	cout << "Enter an integer to set the strength for SCISSORS: ";
	cin >> customScissorsStrength;
	cout << endl;
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
	do 
	{
		cout << "Select your tool: (r) Rock | (p) Paper | (s) Scissors | (e) EXIT" << endl;
		cin >> selection;

		if (selection == 'r' || selection == 'R') 
		{
			return new Rock(customRockStrength);
		}
		else if (selection == 'p' || selection == 'P') 
		{
			return new Paper(customPaperStrength);
		}
		else if (selection == 's' || 'S') 
		{
			return new Scissors(customScissorsStrength);
		}
		else if (selection == 'e' || selection == 'E') 
		{
			return 0;
		}
		else 
		{
			cout << "Sorry, that was an incorrect choice. Please try again." << endl;
		}
	} 
	while (true);
	return 0;
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
** Description: Compares the human and computer to see who wins
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Winner is chosen
*********************************************************************/
void RPSGame::checkFight() 
{
	if (human->fight(*computer)) 
	{
		cout << "Good job Human! You win!" << endl;
		human_wins++;
	}
	else if (computer->fight(*human)) 
	{
		cout << "Computer wins!" << endl;
		computer_wins++;
	}
	else 
	{
		cout << "Tie game." << endl;
		ties++;
	}
	cout << "Human wins: " << human_wins << endl;
	cout << "Computer wins: " << computer_wins << endl;
	cout << "Ties: " << ties << endl;
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
	int strengthSelection;
	cout <<"__________________________________________________________________________" << endl;
	cout <<" ___         _     ___                      ___     _                   _ " << endl;
	cout <<"| _ \___  __| |__ | _ \__ _ _ __  ___ _ _  / __| __(_)______ ___ _ _ __| |" << endl;
	cout <<"|   / _ \/ _| / / |  _/ _` | '_ \/ -_) '_| \__ \/ _| (_-<_-</ _ \ '_(_-<_|" << endl;
	cout <<"|_|_\___/\__|_\_\ |_| \__,_| .__/\___|_|   |___/\__|_/__/__/\___/_| /__(_)" << endl;
	cout <<"                           |_|                                            " << endl;
	cout <<"__________________________________________________________________________" << endl << endl;
	cout <<"~*~*~*~*~*~*~*~*~*~*WELCOME TO ROCK, PAPER, SCISSORS!~*~*~*~*~*~*~*~*~*~*~" << endl;
	cout <<"-----------------------------DIRECTIONS-----------------------------------" << endl;
	cout <<"You will be playing rock, paper, and scissors against the computer! Before\n";
	cout << "we begin, would you like to select the different strengths for the tools?\n";
	cout << "Please enter (1) Yes OR (2) No :" << endl;
	cin >> strengthSelection;
	do {
		if (strengthSelection == 1) 
		{
			chooseStrength();
		}
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
