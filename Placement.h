/**
 * @file Placement.h
 * @author your name (you@domain.com)
 * @brief for the user to set up his battle field
 * @version 0.1
 * @date 2022-12-13 
 */

#ifndef PLACEMENT_H
#define PLACEMENT_H

#include <iostream> 
#include "Boat.h"
#include "board.h"
#include "Position.h"

class placement
{
    private:
        board field; 
        position Row; 
        position Column; 
        // array of boats
        boat fleet[5] = {boat(5), boat(4), boat(3), boat(2), boat(2)};   
    
    public:
        placement()
        {
             
        }; 
        ~placement(){}; 

        void placePieces(); 
};

#endif