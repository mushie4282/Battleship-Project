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
#include <cctype>
#include <cstring>

const int SIZE = 11; // 10 x 10 board size

class board
{
    private:
        char userBattleGround[SIZE][SIZE];
        char userStratBoard[SIZE][SIZE];
        int numB = 65;// print letters using ASCII numbers
        int numA = 0;// print integers into characters
           

    public:
        board() {}; 
        ~board() {}; 
        void fillDefaultBoard();
        void printBoard();
        void placePiece(int column, char letter);// tester method
};

/// @brief use at the START of the game to fill all boards
void board::fillDefaultBoard()
{
    for(int a = 0; a < SIZE; ++a)
    {
        if(a == 0)
        {   
            for(int b = 0; b < SIZE; ++b)
            {
                if(b == 0)
                {
                    userBattleGround[0][0] = '@';
                    userStratBoard[0][0] = '@';
                }
                else
                {
                    // print integers as char
                    char num = numA + '0';
                    userBattleGround[0][b] = num;
                    userStratBoard[0][b] = num; 
                    numA++;
                }
                
            }
        }
        else 
        {
            for(int c = 0; c < SIZE; ++c)
            {
                if(c == 0)
                {
                    userBattleGround[a][0] = char(numB); // typecasting
                    userStratBoard[a][0] = char(numB); // typecasting
                    numB++;
                }
                else
                {
                    userBattleGround[a][c] = '~';
                    userStratBoard[a][c] = '~';
                }
                
            }  
        }
        
    }
}

/// @brief display the board and any time.
void board::printBoard()
{
    std::cout << "Battle Ground\n";
    for(int x = 0; x < SIZE; ++x)
    {
        for(int y = 0; y < SIZE; ++y)
        {
            std::cout << userBattleGround[x][y] << " "; 
        }
        std::cout << std::endl;
    }
    std::cout << "\nYour Placements\n";
    for(int x = 0; x < SIZE; ++x)
    {
        for(int y = 0; y < SIZE; ++y)
        {
            std::cout << userStratBoard[x][y] << " "; 
        }
        std::cout << std::endl;
    }
}


void board::placePiece(int column, char letter)
{
    char upperCaseLetter = toupper(letter); // in case someone inputs a lower case letter
    int row = upperCaseLetter - 'A'; // convert the letter into an applicable row number
    // must shift the numbers by 1 to account for the columns and rows that displays the coordinates
    userBattleGround[row + 1][column + 1] = 'S';
}

#endif