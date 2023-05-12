/**
 * @file ship.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief class for all ships in the game
 * @version 0.1
 * @date 2022-11-21
 */

#ifndef BOAT_H
#define BOAT_H

#include <iostream>
#include <vector> 
#include "spaces.h"

class boat
{
    private:
        int shipSize; // number of spaces the boat occupies
        spaces squares; // keep track of the coordinates the ship is on 

    public: 
        boat(int size) 
        {
            // set the amount of spaces the piece will take
            shipSize = size; 
        }; 
        ~boat(){ };

        int getSpaces() const;
        void decrementShipSize();
        void recordCoordinates(int row, int column);
        int getRowVec(int index) const; 
        int getColumnVec(int index) const; 
};



#endif