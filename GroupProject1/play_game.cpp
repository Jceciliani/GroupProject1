#include <iostream>
#include <string>
#include "RPSGame.h"

int main()
{
    //RPSGame game;
    //game.playRPS();
    //return 0;
    
    RPSGame *game = new RPSGame();
    game->playRPS();
    delete game;
    
    return 0;
    
    
    
}

