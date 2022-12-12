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
// #include <cstring>

const int SIZE = 11; // 10 x 10 board size

class board
{
    private:
    // i had both boards as static char, but it was given undefined errors for board.cpp 
        char shadowBoard[SIZE][SIZE]; // user's selection board that tells whether he had sunk any ships
        char userBoard[SIZE][SIZE]; // user's placement 
        // char (*ptrShadow)[SIZE] = shadowBoard; // shadow board array pointer
        // char (*ptrUser)[SIZE] = userBoard; // user board array pointer
        int numB = 65;// print letters using ASCII numbers
        int numA = 0;// print integers into characters

        void fillDefaultBoard(char user[SIZE][SIZE], char shadow[SIZE][SIZE]); // we don't need a ptr bc it is only used once (hopefully)
        bool setPiece(int column, char letter, char piece); // place piece on user board

    public:
        board() {
            fillDefaultBoard(userBoard,shadowBoard);
            std::cout << "Created Board\n";
        }; 
        ~board() {}; 
        
        void printBoard();

        // use this function in the game class to populate the board before starting turns
        void fillBoard() // populate game board
        {
            fillDefaultBoard(userBoard,shadowBoard);
        }

        bool placePiece(int columnNum, int rowLetter, char piece)
        {
            return setPiece(columnNum, rowLetter, piece);
        }

        char (&getUserBoard())[SIZE][SIZE]
        {
            return userBoard;
        }

        char (&getShadowBoard())[SIZE][SIZE]
        {
            return shadowBoard;
        }
};

#endif