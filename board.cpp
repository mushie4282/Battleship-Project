/**
 * @file board.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief game board implementation 
 * @version 0.1
 * @date 2022-12-09
 */

#include <iostream>
#include "board.h"

/// @brief use at the START of the game to fill all boards
void board::fillDefaultBoard(char shadow[SIZE][SIZE], char board[SIZE][SIZE])
{
    for(int a = 0; a < SIZE; ++a)
    {
        if(a == 0)
        {   
            // column headings as numbers
            for(int b = 0; b < SIZE; ++b)
            {
                if(b == 0)
                {
                    shadow[0][0] = '@';
                    board[0][0] = '@';
                    // *(*(shadow + 0) + 0) = '@';
                    // *(*(board + 0) + 0) = '@';
                    // *(*(ptr + a) + b)
                }
                else
                {
                    // print integers as char
                    char num = numA + '0';
                    shadow[0][b] = num;
                    board[0][b] = num; 
                    // *(*(shadow + 0) + b) = num;
                    // *(*(board + 0) + b) = num;
                    numA++;
                }
                
            }
        }
        else 
        {
            // tilda character as placement holders
            for(int c = 0; c < SIZE; ++c)
            {
                // row header
                if(c == 0)
                {
                    shadow[a][0] = char(numB); // typecasting
                    board[a][0] = char(numB); // typecasting
                    // *(*(shadow + a) + 0) = char(numB);
                    // *(*(board + a) + 0) = char(numB);
                    numB++;
                }
                else
                {
                    shadow[a][c] = '~';
                    board[a][c] = '~';
                    // *(*(shadow + a) + c) = '~';
                    // *(*(board + a) + c) = '~';
                }
                
            }  
        }
        
    }
}

/// @brief display the board at any time.
void board::printBoard()
{
    std::cout << "\n   Battle Ground\n";
    for(int x = 0; x < SIZE; ++x)
    {
        for(int y = 0; y < SIZE; ++y)
        {
            std::cout << shadowBoard[x][y] << " ";
        }
        std::cout << std::endl;
    } 
    std::cout << "\n   Your Placements\n";
    for(int x = 0; x < SIZE; ++x)
    {
        for(int y = 0; y < SIZE; ++y)
        {
            std::cout << userBoard[x][y] << " "; 
        }
        std::cout << std::endl;
    }
}


bool board::setPiece(int column, char letter, char piece)
{
    char upperCaseLetter = toupper(letter); // in case someone inputs a lower case letter
    int row = upperCaseLetter - 'A'; // convert the letter into an applicable row number

    // check if the slot is taken
    if(userBoard[row][column] == '~')
    {
        userBoard[row][column] = piece;
        return true;
    }
    else
    {
        return false; 
    }

    // // must shift the numbers by 1 to account for the columns and rows that displays the coordinates
    // *(*(board + row + 1) + column + 1) = piece; 
}