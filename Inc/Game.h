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
#include <cmath>
#include "User.h"
#include "board.h"
#include "Placement.h"
#include "Boat.h"
#include "Position.h"
#include "Ability.h"

class game 
{
    private:
        user player;
        user opponent; // computer
        board field;
        placement ship;
        ability turn;
        ability computer; 
        int count; // max amount of attacks for the user before the game ends
        int userScore, compScore; 

    public: 
        game()
        {   userScore = compScore = 0; 
            field.populateBoard();
            count = pow(SIZE - 1, 2); // 81 squares on the game board 
            std::cout << "Start of BATTLESHIP Game! WELCOME!!\n";
        };
        ~game(){};

        // the main game loop, which calls other member functions to handle user input, computer turns, and game updates. 
        void gamePlay(); // entire game play will be held in this function 
};

#endif