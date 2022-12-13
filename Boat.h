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
#include "board.h"
#include "Dimension.h"

#define SIZE 10

class boat
{
    private: 
        int spaces = 0; // ship size
        dimension size;

    public: 
        boat(int spaces) 
        {
            // set the amount of spaces the piece will take
            size.setShipSize(spaces);
        }; 
        ~boat(){ };
};

#endif