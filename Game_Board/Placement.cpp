/**
 * @file Placement.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief players will use the functions once to set their boards
 * @version 0.1
 * @date 2022-12-13
 */
#include "Placement.h"

/**
 * @brief Placement of the user's ships in the beginning of the game
 * 
 */
void placement::placePieces()
{
    std::cout << "Set your battlefield!\n"; 

    for(int z = 0; z < 5; ++z)
    {
        std::cout << "Ship " << z + 1 << std::endl; 
        std::cout << "Size: " << fleet[z].getSpaces() << std::endl; 
        Row.setRowLetter(); 
        Column.setColumnNum(); 
        shape.setVerticalFlag();
        // use the board's function to place the boat
        field.setPiece(Column.getColumnNum(), Row.getRowLetter(), fleet[z].getSpaces(), shape.getVerticalFlag());
        field.displayBoard(); 
    }    
}

/**
 * @brief 
 * 
 */
void placement::CPUplacement()
{
    // generate random placements of ships of the board
    srand(time(0));
    int tempRow, tempColumn; 

    for(int i = 0; i < 5; i++)
    {
        // psuedo random numbers from 1 - 9
        int randomRow = rand() % 9 + 1; 
        tempRow = randomRow;
        int randomColumn = rand() % 9 + 1;
        tempColumn = randomColumn;
        
        for(int a = 0; a < fleet[i].getSpaces(); ++a)
        {
            board::shadowBoard[randomRow][randomColumn] = 'S';

            // keep track of the computer's coordinates
            fleet[i].recordCoordinates(randomRow, randomColumn);

            if(i % 2) // VERTICAL PLACEMENT
            {
                if(tempRow <= fleet[i].getSpaces())
                {
                    ++randomRow;
                }
                else
                {
                    --randomRow; 
                }
            }
            else // HORIZONTAL PLACEMENT
            {
                // place right when the column num is too small
                if(tempColumn <= fleet[i].getSpaces())
                {
                    ++randomColumn;
                }
                // place left when the column num is too large
                else
                {
                    --randomColumn;  
                }  
            }
        }
    }
}