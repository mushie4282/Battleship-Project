/**
 * @file Ability.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief Objects of this class will use the attack functions to launch missles 
 * @version 0.1
 * @date 2022-12-15 
 */

#include "Ability.h"

/**
 * @brief attack opponent's board
 * - if there is a ship part -> 'X' will be placed
 * - we will check the board if a ship space has been hit
 * - if there is no ship part -> 'O' will be placed
 * 
 * @param name user class object
 */
void ability::attack(user name)
{
    // collect attack coordinate
    std::cout << "Choose coordinates to attack:\n"; 
    row.setRowLetter(); 
    column.setColumnNum();

    if(board::shadowBoard[row.getRowLetter()][column.getColumnNum()] == 'S')
    {
        board::opponentBoard[row.getRowLetter()][column.getColumnNum()] = 'X';
        countHits(row.getRowLetter(), column.getColumnNum(), name);
        sunk = true;
    }
    else
    {
        board::opponentBoard[row.getRowLetter()][column.getColumnNum()] = 'o';
        sunk = false; 
    }
}

/**
 * @brief return flag that indicates whether a boat space has been hit
 * 
 * @return true boat space hit
 * @return false attack missed 
 */
bool ability::getSunkFlag() const
{
    return sunk; 
}


/**
 * @brief Use multiple for loops to check if the coordinates match any in the boats' parallel vectors
 *  - we did not get the function to work properly
 * 
 * @param rowLetter int
 * @param columnNum int
 * @param name user
 */
void ability::countHits(int rowLetter, int columnNum, user name)
{
    std::cout << "enter countHits\n";
    bool dead = false; 
    for(int i = 0; i < 5; ++i)
    {
        if(rowLetter == aircraftCarrier.getRowVec(i) && columnNum == aircraftCarrier.getColumnVec(i))
        {
            aircraftCarrier.decrementShipSize();
            dead = aircraftCarrier.getSpaces() == 0;
            name.decrementBoatNum(dead);
            std::cout << "Aircraft: " << name.getBoatAmt() << " " << dead << std::endl; 
            return;  
        }  
    }
    for(int c = 0; c < 4; ++c)
    {
        if(rowLetter == battleShip.getRowVec(c) && columnNum == battleShip.getColumnVec(c))
        {
            battleShip.decrementShipSize();
            dead = battleShip.getSpaces() == 0;
            name.decrementBoatNum(dead);
            std::cout << "Battleship: " << name.getBoatAmt() << " " << dead << std::endl;
            return; 
        }
    }
    for(int i = 0; i < 3; ++i)
    {
        if(rowLetter == submarine.getRowVec(i) && columnNum == submarine.getColumnVec(i))
        {
            submarine.decrementShipSize();
            dead = submarine.getSpaces() == 0;
            name.decrementBoatNum(dead);
            std::cout << "Battleship: " << name.getBoatAmt() << " " << dead << std::endl;
            return; 
        }
        else if(rowLetter == cruiser.getRowVec(i) && columnNum == cruiser.getColumnVec(i))
        {
            cruiser.decrementShipSize();
            dead = cruiser.getSpaces() == 0;
            name.decrementBoatNum(dead);
            std::cout << "Cruiser: " << name.getBoatAmt() << " " << dead << std::endl;
            return; 
        }
    }
    for(int j = 0; j < 2; ++j)
    {
        if(rowLetter == destroyer.getRowVec(j) && columnNum == destroyer.getColumnVec(j))
        {
            destroyer.decrementShipSize();
            dead = destroyer.getSpaces() == 0;
            name.decrementBoatNum(dead);
            std::cout << "Destroyer: " << name.getBoatAmt() << " " << dead << std::endl;
            return; 
        }
    }           
}

/**
 * @brief computer randomly generates coordinates to attack the user's game board
 *  - there can be repeated coordinates
 * 
 */
void ability::CPUattack()
{
    // srand() seeds the random number generator with the current time, 
    // so that the numbers generated will be different each time the program is run
    srand(time(0)); 
    int randomRow = rand() % 9 + 1; 
    int randomColumn = rand() % 9 + 1; 

    // check if it is a ship or a regenerated coordinate
    if(board::userBoard[randomRow][randomColumn] == 'S' || board::userBoard[randomRow][randomColumn] == 'X')
    {
        board::userBoard[randomRow][randomColumn] = 'X';
        sunk = true; 
    }
    else
    {
        board::userBoard[randomRow][randomColumn] = 'o';
    }
}