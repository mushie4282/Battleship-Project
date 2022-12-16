/**
 * @file ship.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief abstract class for all ships in the game
 * @version 0.1
 * @date 2022-11-21
 */

#ifndef BOAT_H
#define BOAT_H

#include <iostream>
#include <vector> 

class boat
{
    private:
        int shipSize; // number of spaces the boat occupies
        // keep track of the coordinates the ship is on
        static std::vector<int> rowVec; 
        static std::vector<int> columnVec;

    public: 
        boat(int spaces) 
        {
            // set the amount of spaces the piece will take
            shipSize = spaces; 
        }; 
        ~boat(){ };

        int getSpaces() const;
        void decrementShipSize();
        void recordCoordinates(int row, int column);
        void removeCoordinates(int row, int column);
        int getVecSize();
        int getRowVec(int index) const; 
        int getColumnVec(int index) const;   
};



#endif