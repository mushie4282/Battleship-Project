/**
 * @file Game.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief the abstract game logic will be transacted in this file
 * @version 0.1
 * @date 2022-12-09
 */

#ifndef GAME_CPP
#define GAME_CPP

#include <iostream>
#include "board.h"
#include "ship.h"
#include "player.h"
#include "AircraftCarrier.h"


class game 
{
    private: 
        board* field;
        Player user; 
        bool winner = false; 
        int rowLetter; 
        char columnNum;

        void coordinates(); 

    public: 
        game()
        {
           std::cout << "Start of BATTLESHIP Game! WELCOME!!\n";
        };
        ~game(){};

        void gamePlay(); 

};

void game::coordinates()
{
    std::cout << "Enter row letter: ";
    std::cin >> rowLetter; 
    while(rowLetter > 'K')
    {
        std::cout << "Invalid row, try again: ";
        std::cin >> rowLetter;
    }
    std::cout << "\n Enter column number: ";
    std::cin >> columnNum; 
    while(columnNum > 10)
    {
        std::cout << "Invalid colum, try again: ";
        std::cin >> columnNum; 
    }
}

void game::gamePlay()
{
    user.whoGoesFirst(); // quiz the user to see who goes first
    
    // while there is NO winner
    while(!winner)
    {
        // consistently print the updated board

        field->printBoard(); 

        // check if the user is going first
        if(user.getFlag())
        {
            // start their turn
            std::cout << "Start their turn\n";
            coordinates(); // grab coordinates
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

#endif