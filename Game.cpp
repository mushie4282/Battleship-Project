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

    // quiz the user to see who goes first
    user.whoGoesFirst();

    // while there is NO winner
    while(!getWinnerFlag())
    {
        // consistently print the updated board
        field->displayBoard();
        
        // check if the user is going first
        if(user.getFlag())
        {
            // start their turn
            std::cout << "Start their turn\n";
            rowPos.setRowLetter(); 
            colPos.setColumnNum(); 
            std::cout << "Your Coordinates are: " << rowPos.getRowLetter() << " " << colPos.getColumnNum() << std::endl;
            winner = true; 
        }
        else
        {
            // show computer hitting their map
            std::cout << "Computer Starts\n";
            winner = true;  
        }
    }

}
