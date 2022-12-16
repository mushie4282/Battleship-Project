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
    // player.whoGoesFirst();
    
    // if(player.getUserFirst())
    // {
    //     std::cout << "You attack first!\n";
    // }
    // else
    // {
    //     std::cout << "Computer attacks first :(\n"; 
    // }

    // place 5 ships
    ship.placePieces();

    // main game loop
    while(player.getBoatAmt() != 0) // should check if the CPU's boat amount is also not zero
    {
        std::cout << player.getBoatAmt() << std::endl;
        // either user goes first or CPU goes first || player.getUserFirst()
        if(1)
        {
            turn.attack(player);
            // CPU attacks
            if(turn.getSunkFlag()) // if there is a hit, track the amount of ships left
            {
                std::cout << "Hit!!\n";
                // std::cout << player.getBoatAmt() << std::endl;
            }
            else
            {
                std::cout << "Miss\n";
            }
        }
        else
        {
            // CPU attacks
            turn.attack(player);
            if(turn.getSunkFlag()) // if there is a hit, track the amount of ships left
            {
                std::cout << "Hit!!\n";
            }
            else
            {
                std::cout << "Miss\n";
            }
        }

        field.displayBoard(); 
    }
}
