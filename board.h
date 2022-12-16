/**
 * @file board.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief Battleship 10x10 board
 * @version 0.1
 * @date 2022-11-21
 */

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
#include "Position.h"
#include "Boat.h"
#include "User.h"

#define SIZE 10

class board
{
    private:
        position Row; 
        position Column;
        boat aircraftCarrier = boat(5);
        boat battleShip = boat(4);
        boat cruiser = boat(3); 
        boat submarine = boat(3);
        boat destroyer = boat(2);
        int count = 0; 
        // these static variables are initialized in the constructor of game.h
        static char opponentBoard[SIZE][SIZE]; // user's selection board that tells whether he had sunk any ships
        static char userBoard[SIZE][SIZE]; // user's placement
   
    public:
        board(){}; 
        ~board() {}; 
        
        void displayBoard();

        void populateBoard(); // only use once

        void setPiece(int columnNum, int rowLetter, int size, bool flag); // only use once

        bool attack(int rowLetter, int columnNum, user name);

        void countHits(int rowLetter, int columnNum, user name);  
};

#endif