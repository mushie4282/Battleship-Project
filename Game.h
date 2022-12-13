/**
 * @file Game.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief Game class header file
 * @version 0.1
 * @date 2022-12-11
 */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "User.h"
#include "board.h"
#include "Placement.h"
#include "Boat.h"
#include "Position.h"
#include "endGame.h"

class game 
{
    private:
        user player;
        user opponent; // use a random number generator when it's the computer's turn
        board field;
        board location; 
        endGame winner;
        placement ship;
        boat aircraftCarrier = boat(5);
        boat battleShip = boat(4);
        boat cruiser = boat(3); 
        boat submarine = boat(3); 
        boat destroyer = boat(2);
        
        int numOfShips = 5; 

    public: 
        game()
        {   
            field.populateBoard(); 
            std::cout << "Start of BATTLESHIP Game! WELCOME!!\n";
        };
        ~game(){};

        // the main game loop, which calls other member functions to handle user input, computer turns, and game updates. 
        void gamePlay(); // entire game play will be held in this function 
};

#endif