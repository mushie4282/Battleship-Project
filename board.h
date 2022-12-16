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
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
#include "Position.h"
#include "Boat.h"
#include "User.h"

#define SIZE 10

class board
{
    private:
        position Row; 
        position Column;
        // boat vectors to keep track of coordinates
        boat aircraftCarrier = boat(5);
        boat battleShip = boat(4);
        boat cruiser = boat(3); 
        boat submarine = boat(3);
        boat destroyer = boat(2);
        int count = 0; // for setPiece function to switch
   
    public:
        board(){}; 
        ~board() {}; 

        // these static variables are initialized in the constructor of game.h
        // they are public to easily share the boards among other classes
        static char opponentBoard[SIZE][SIZE]; // user's selection board that tells whether he had sunk any ships
        static char shadowBoard[SIZE][SIZE]; // computer's placement
        static char userBoard[SIZE][SIZE]; // user's placement
        
        void displayBoard();

        void populateBoard(); // only use once

        void setPiece(int columnNum, int rowLetter, int size, bool flag); // only use once

        void CPUattack();  
};

#endif