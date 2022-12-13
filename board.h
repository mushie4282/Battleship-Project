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

#define ROW 9
#define COLUMN 10

class board
{
    private: 
        static char opponentBoard[ROW][COLUMN]; // user's selection board that tells whether he had sunk any ships
        static char userBoard[ROW][COLUMN]; // user's placement
        // char (*ptrShadow)[SIZE] = opponentBoard; // opponent board array pointer
        // char (*ptrUser)[SIZE] = userBoard; // user board array pointers
        int asciiNum = 65;// print letters using ASCII numbers
        int intChar = 0;// print integers into characters
        
    public:
        board(){
            std::cout << "Created Board\n";
        }; 
        ~board() {}; 
        
        void displayBoard();

        void populateBoard();

        bool placePiece(int columnNum, int rowLetter, char piece); 
};

#endif