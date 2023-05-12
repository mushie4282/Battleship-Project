/**
 * @file spaces.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief keep track of coordinates
 * @version 0.1
 * @date 2022-12-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "spaces.h"

std::vector<int> spaces::rowVec; 
std::vector<int> spaces::columnVec; 

/**
 * @brief store the coordinates in two seperate vectors for the use of checking whether a certain boat has sunk
 * 
 * @param row 
 * @param column 
 */
void spaces::recordCoordinates(int row, int column)
{
    rowVec.push_back(row); 
    columnVec.push_back(column); 
}

/**
 * @brief value at index
 * 
 * @param index 
 * @return int value of the vector index 
 */
int spaces::getRowVec(int index) const
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

/**
 * @brief value at index
 * 
 * @param index 
 * @return int value of the vector index 
 */
int spaces::getColumnVec(int index) const
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