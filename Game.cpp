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
    
    // computer places ships
    ship.CPUplacement(); 

    // place 5 ships
    ship.placePieces();

    // main game loop
    // to win: 
    // either player sinks all the boats or the user uses up all 81 turns
    while(player.getBoatAmt() != 0 || opponent.getBoatAmt() != 0 || count > 0) // should check if the CPU's boat amount is also not zero
    {
        // either user goes first or CPU goes first || player.getUserFirst()
        if(1)
        {
            turn.attack(player); // user attacks
            computer.CPUattack(); // CPU attacks
            if(turn.getSunkFlag()) // if there is a hit, track the amount of ships left
            {
                ++userScore; 
                // 5 boats take 17 squares on the board
                if(userScore == 17)
                {
                    return; // end game b/c user has sunk all 5 boats
                }
                std::cout << "Hit!!\n";
            }
            else
            {
                std::cout << "Miss\n";
            }
        }
        else
        {
            computer.CPUattack(); // CPU attacks
            turn.attack(player); // user attacks
            if(computer.getSunkFlag()) // if there is a hit, track the amount of ships left
            {
                ++compScore;
                // 5 boats take 17 squares on the board
                if(compScore == 17)
                {
                    return; // end game b/c user has sunk all 5 boats
                }
                std::cout << "Hit!!\n";
            }
            else
            {
                std::cout << "Miss\n";
            }
        }

        field.displayBoard();
        // decrement amount of turns
        --count; // decrement amount of turns left 
        std::cout << "You have " << count << " attempts left\n";
    }
    
    // if the while loops ends with number of turns == 1
    if(count == 1)
    {
        if(userScore > compScore)
        {
            std::cout << "You have won by the number of hits!\n";
            std::cout << "Total Hits: " << userScore << std::endl;
            std::cout << "Computer Total Hits: " << compScore << std::endl;
        }
        else
        {
            std::cout << "You have lost by the number of hits. :(\n";
            std::cout << "Total Hits: " << userScore << std::endl;
            std::cout << "Computer Total Hits: " << compScore << std::endl;
        }
    }
    
    // End Game message
    std::cout << "Game Over\n";
}
