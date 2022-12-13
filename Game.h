/**
 * @file Game.h
 * @author your name (you@domain.com)
 * @brief Game class header file
 * @version 0.1
 * @date 2022-12-11
 */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "player.h"
#include "board.h" 
#include "AircraftCarrier.h"
#include "Row.h"
#include "Column.h"
#include "Shape.h"
#include "ship.h"

#define SIZE 11

class game 
{
    private:
        Player user; // user object
        // AircraftCarrier firstShip;
        Row rowPos; // row position
        Column colPos; // column position
        board* field; 
        
        char opponentBoard[SIZE][SIZE]; // user's selection board that tells whether he had sunk any ships
        char** userBoard; // point to the board from a different class
        bool winner = false; // flag to stop the game once someone wins

        bool getWinnerFlag(){return winner;};

    public: 
        game()
        {   
            std::cout << "Start of BATTLESHIP Game! WELCOME!!\n";
        };
        ~game(){};

        // the main game loop, which calls other member functions to handle user input, computer turns, and game updates. 
        void gamePlay(); // entire game play will be held in this function 
};

#endif