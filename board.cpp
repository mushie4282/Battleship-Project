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
    std::cout << "\n     Opponent's\n";
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


void board::setPiece(int columnNum, int rowLetter, int size)
{
    // dimension shape; // option of vertical or horizontal placement

    for(int i = 0; i < size; ++i)
    { 
        // if the first choice is not available, ask again
        // != '~' did not work -> use ascii num 126
        while(userBoard[rowLetter][columnNum] != 126)
        {
            std::cout << "Ship could not be placed\n";
            Row.setRowLetter(); 
            Column.setColumnNum(); 
            rowLetter = Row.getRowLetter();
            columnNum = Column.getColumnNum(); 
        }
        
        // when the space is empty place ship
        userBoard[rowLetter][columnNum] = 'S';
        // place right when the column num is too small
        if(columnNum <= size)
        {
            ++columnNum;
        }
        // place left when the column num is too large
        else
        {
            --columnNum;  
        }
    }

    displayBoard();
}

/**
 * @brief selecting where to attack
 * 
 * @param columnNum 
 * @param rowLetter 
 * @return true ship has sunk
 * @return false ship is still a float
 */
void board::attack()
{
    std::cout << "Where do you want to attack?\n"; 
    Row.setRowLetter(); 
    Column.setColumnNum(); 

    opponentBoard[Row.getRowLetter()][Column.getColumnNum()] = 'X';  
}