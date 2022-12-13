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

class boat
{
    private:
        int shipSize; 

    public: 
        boat(int spaces) 
        {
            // set the amount of spaces the piece will take
            shipSize = spaces; 
        }; 
        ~boat(){ };

        int getSpaces() const;
        void changeShipSize(bool flag);  
};

#endif