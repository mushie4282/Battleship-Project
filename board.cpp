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

/**
 * @brief attack opponent's board
 *      - if there is a ship part -> 'X' will be placed
 *      - we will check the board if a ship space has been hit
 *      - if there is no ship part -> 'O' will be placed
 * 
 * @param rowLetter 
 * @param columnNum 
 */
bool board::attack(int rowLetter, int columnNum, user name)
{
    // until we figure out how to hide the hidden board, use the user's board instead
    if(userBoard[rowLetter][columnNum] == 'S')
    {
        opponentBoard[rowLetter][columnNum] = 'X';
        countHits(rowLetter, columnNum, name);
        return true;
    }
    else
    {
        opponentBoard[rowLetter][columnNum] = 'O';
        return false; 
    }
}

/**
 * @brief Use multiple for loops to check if the coordinates match any in the boats' vectors
 * 
 * @param rowLetter int
 * @param columnNum int
 * @param name user
 */
void board::countHits(int rowLetter, int columnNum, user name)
{
    for(int i = 0; i < aircraftCarrier.getSpaces(); ++i)
    {
        if(rowLetter == aircraftCarrier.getRowVec(i) && columnNum == aircraftCarrier.getColumnVec(i))
        {
            aircraftCarrier.decrementShipSize();
            name.decrementBoatNum(aircraftCarrier.getSpaces() == 0);
            return;  
        }  
    }
    for(int c = 0; c < battleShip.getSpaces(); ++c)
    {
        if(rowLetter == battleShip.getRowVec(c) && columnNum == battleShip.getColumnVec(c))
        {
            battleShip.decrementShipSize();
            name.decrementBoatNum(battleShip.getSpaces() == 0);
            return; 
        }
    }
    for(int i = 0; i < submarine.getSpaces(); ++i)
    {
        if(rowLetter == submarine.getRowVec(i) && columnNum == submarine.getColumnVec(i))
        {
            submarine.decrementShipSize();
            name.decrementBoatNum(submarine.getSpaces() == 0);
            return; 
        }  
    }
    for(int c = 0; c < cruiser.getSpaces(); ++c)
    {
        if(rowLetter == cruiser.getRowVec(c) && columnNum == cruiser.getColumnVec(c))
        {
            cruiser.decrementShipSize();
            name.decrementBoatNum(cruiser.getSpaces() == 0);
            return; 
        }
    }
    for(int j = 0; j < destroyer.getSpaces(); ++j)
    {
        if(rowLetter == destroyer.getRowVec(j) && columnNum == destroyer.getColumnVec(j))
        {
            destroyer.decrementShipSize();
            name.decrementBoatNum(destroyer.getSpaces() == 0);
            return; 
        }
    }           
}