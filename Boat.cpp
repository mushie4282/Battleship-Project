/**
 * @file Boat.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-13
 */

#include "Boat.h"

std::vector<int> boat::rowVec; 
std::vector<int> boat::columnVec;

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
    rowVec.push_back(row); 
    columnVec.push_back(column); 
}

int boat::getRowVec(int index) const
{
    if(index > rowVec.size())
    {
        return -1; 
    }
    else
    {
        return rowVec[index]; 
    }
    
}
int boat::getColumnVec(int index) const
{
    if(index > columnVec.size())
    {
        return -1; 
    }
    else
    {
      return columnVec[index];   
    }
}

void boat::removeCoordinates(int row, int column)
{
    rowVec.pop_back();
    columnVec.pop_back(); 
}

/**
 * @brief get any vectors' size
 *  - any vector size would work because the two vectors are in parallel
 * 
 * @return int vector size
 */
int boat::getVecSize()
{
    return rowVec.size(); 
}