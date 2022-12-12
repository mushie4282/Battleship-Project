/**
 * @file AircraftCarrier.cpp
 * @author your name (you@domain.com)
 * @brief Aircraft Carrier Implementation file
 * @version 0.1
 * @date 2022-12-11
 */

#include "AircraftCarrier.h"

/*************** AIRCRAFT CARRIER ****************/
/// @brief Place 5 characters on the board to represent an aircraft carrier
/// we check whether the orientation is vertical or not 
/// we use ship class space variable as a for loop parameter
/// @param column integer
/// @param row character
void AircraftCarrier::placement(int column, char row)
{
    bool temp = true; 
    //setOrientation(); // user input of orientation placement

    // VERTICAL
    if(getOrientation())
    {
        if(column > 5)
        {
            for(int i = 0; i < getSpaces(); ++i)
            {
                temp = userBoard->placePiece(column - i, row, piece);
            }  
        }
        else
        {
            for(int i = 0; i < getSpaces(); ++i)
            {
                temp = userBoard->placePiece(column + i, row, piece);
            } 
        } 
    }
    
    // HORIZONTAL
    if(!getOrientation())
    {
        if(row > 'F') 
        {
            for(int i = 0; i < getSpaces(); ++i)
            {
                temp = userBoard->placePiece(column, row - i, piece);
            }
        }
        else
        {
            for(int i = 0; i < getSpaces(); ++i)
            {
                temp = userBoard->placePiece(column, row + i, piece);
            }  
        }
    }
    
};

/*************** END AIRCRAFT CARRIER ****************/