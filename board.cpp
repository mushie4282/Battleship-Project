/**
 * @file board.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief game board implementation 
 * @version 0.1
 * @date 2022-12-09
 */

#include "board.h"

char board::opponentBoard[SIZE][SIZE];
char board::userBoard[SIZE][SIZE];

/// @brief populate the game board from a text file rather than multiple for loops
void board::populateBoard()
{
    int row = 0; 
    int column = 0; 
    char temp; 
    std::ifstream input; 
    input.open("gameField.txt");

    while(!input.eof())
    {  
        input >> temp;
        userBoard[row][column] = temp;
        opponentBoard[row][column] = temp; 
        if(column < 9)
        {
            column++;
        }
        else if(column == 9)
        {
            column = 0; 
            row++; 
        }
    }
}

/// @brief display the board at any time.
void board::displayBoard()
{
    std::cout << "\n   Opponent's\n";
    for(int x = 0; x < SIZE; ++x)
    {   
        for(int y = 0; y < SIZE; ++y)
        {
            std::cout << opponentBoard[x][y] << " ";
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


bool board::placePiece(int columnNum, int rowLetter, char piece)
{
    char upperCaseLetter = toupper(rowLetter); // in case someone inputs a lower case letter
    int row = upperCaseLetter - 'A'; // convert the letter into an applicable row number

    // check if the slot is taken
    if(userBoard[row][columnNum] == '~')
    {
        userBoard[row][columnNum] = piece;
        return true;
    }
    else
    {
        return false; 
    }

    // // must shift the numbers by 1 to account for the columns and rows that displays the coordinates
    // *(*(board + row + 1) + column + 1) = piece; 
}
