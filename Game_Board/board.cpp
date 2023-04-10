/**
 * @file board.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief game board implementation 
 * @version 0.1
 * @date 2022-12-09
 */

#include "board.h"

char board::userBoard[SIZE][SIZE];
char board::opponentBoard[SIZE][SIZE];
char board::shadowBoard[SIZE][SIZE];

/**
 * @brief Populate game boards with an external txt file
 *  - Computer will randomly set the 5 ships in place by the time the function ends
 * 
 */
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
        shadowBoard[row][column] = temp;  
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
    std::cout << "\n Your Placements\n";
    for(int x = 0; x < SIZE; ++x)
    {
        for(int y = 0; y < SIZE; ++y)
        {
            std::cout << userBoard[x][y] << " "; 
        }
        std::cout << std::endl;
    }
}

/**
 * @brief This function is only used in the beginning of the game to set the 5 ships
 * 
 * @param columnNum 
 * @param rowLetter 
 * @param size number of squares the boat will occupy
 * @param flag whether the user wants to place the boat vertical or not
 */
void board::setPiece(int columnNum, int rowLetter, int size, bool flag)
{
    //hold the value of the first coordinate so that all the ship squares can be placed
    int tempRow(rowLetter), tempColumn(columnNum); 
    count++; // to switch between submarine and crusier 
    while(userBoard[rowLetter][columnNum] != '~')
    {
        std::cout << "Ship could not be placed" << std::endl; 
        Row.setRowLetter(); 
        Column.setColumnNum(); 
        rowLetter = Row.getRowLetter();
        columnNum = Column.getColumnNum(); 
    }

    for(int a = 0; a < size; ++a)
    {
        userBoard[rowLetter][columnNum] = 'S'; 

        // track the coordinates of the boat in two seperate vectors
        switch(size)
        {
            case 5:
                aircraftCarrier.recordCoordinates(rowLetter, columnNum);
                break;
            case 4:
                battleShip.recordCoordinates(rowLetter,columnNum);
                break;
            case 3:
            // when count is odd, we have reaced the submarine boat
                if(count % 2)
                {
                    submarine.recordCoordinates(rowLetter,columnNum); 
                }
                else
                {
                    cruiser.recordCoordinates(rowLetter, columnNum);
                }
                break;
            case 2:
                destroyer.recordCoordinates(rowLetter,columnNum); 
                break;
        }

        if(flag) // VERTICAL PLACEMENT
        {
            if(tempRow <= size)
            {
                ++rowLetter;
            }
            else
            {
                --rowLetter; 
            }
        }
        else // HORIZONTAL PLACEMENT
        {
            // place right when the column num is too small
            if(tempColumn <= size)
            {
                ++columnNum;
            }
            // place left when the column num is too large
            else
            {
                --columnNum;  
            }  
        }
    }
}
