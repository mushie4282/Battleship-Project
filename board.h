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
#include "Dimension.h"
#include "Position.h"

#define SIZE 10

class board
{
    private:
        position Row; 
        position Column;
        static char opponentBoard[SIZE][SIZE]; // user's selection board that tells whether he had sunk any ships
        static char userBoard[SIZE][SIZE]; // user's placement
   
    public:
        board(){}; 
        ~board() {}; 
        
        void displayBoard();

        void populateBoard();

        void setPiece(int columnNum, int rowLetter, int size); 

        void attack(); 
};

#endif