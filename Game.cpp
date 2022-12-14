/**
 * @file Game.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief the abstract game logic will be transacted in this file
 * @version 0.1
 * @date 2022-12-09
 */

#include "Game.h"


/// @brief the main game loop, which calls other member functions to handle user input, computer turns, and game updates.
void game::gamePlay()
{
    srand(time(0)); // for psuedo random number generated within the player class

    field.displayBoard(); // display battlefield for user reference
    
    // quiz the user to see if he will attack first
    player.whoGoesFirst();
    
    if(player.getUserFirst())
    {
        std::cout << "You attack first!\n";
    }
    else
    {
        std::cout << "Computer attacks first :(\n"; 
    }

    // place 5 ships
    ship.placePieces();

    // while there is NO winner
    while(!winner.getGameFlag())
    {
        // // consistently print the updated board
        // field.displayBoard();          
            
        // attack
        // location.attack(); 
        
        // check if all 5 ships are still alive
        // yes -> keep going
        // no -> end game

        winner.setGameFlag(true);  
    }

}
