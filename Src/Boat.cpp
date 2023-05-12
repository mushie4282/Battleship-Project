/**
 * @file Boat.cpp
 * @author your name (you@domain.com)
 * @brief class for all ships in the game
 * @version 0.1
 * @date 2022-12-13
 */

#include "Boat.h"

/**
 * @brief get the number of spaces the boat occupies
 * 
 * @return int 
 */
int boat::getSpaces() const
{
    return shipSize; 
}

/**
 * @brief decrease number of spaces the boat has left
 * 
 * @param flag 
 */
void boat::decrementShipSize()
{
    --shipSize;
}

/**
 * @brief store the coordinates in two seperate vectors for the use of checking whether a certain boat has sunk
 * 
 * @param row 
 * @param column 
 */
void boat::recordCoordinates(int row, int column)
{
    squares.recordCoordinates(row, column);
}

/**
 * @brief value at index
 * 
 * @param index 
 * @return int value of the vector index 
 */
int boat::getRowVec(int index) const
{
    return squares.getRowVec(index); 
}

/**
 * @brief value at index
 * 
 * @param index 
 * @return int value of the vector index 
 */
int boat::getColumnVec(int index) const
{
    return squares.getColumnVec(index); 
}