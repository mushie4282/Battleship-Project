/**
 * @file Placement.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief players will use the functions once to set their boards
 * @version 0.1
 * @date 2022-12-13 
 */

#ifndef PLACEMENT_H
#define PLACEMENT_H

#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
#include "Boat.h"
#include "board.h"
#include "Position.h"
#include "Dimension.h"

class placement
{
    private:
        board field; 
        position Row; 
        position Column;
        dimension shape; 
        // array of boats
        boat fleet[5] = {boat(5), boat(4), boat(3), boat(3), boat(2)};  
    
    public:
        placement()
        {
             
        }; 
        ~placement(){}; 

        void placePieces();
        void CPUplacement(); 
};

#endif