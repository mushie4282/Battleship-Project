/**
 * @file Ability.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief Objects of this class will use the attack functions to launch missles 
 * @version 0.1
 * @date 2022-12-15
 */

#ifndef ABILITY_H
#define ABILITY_H

#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
#include "board.h"
#include "User.h"
#include "Position.h"
#include "Boat.h"

class ability
{
    private:
        bool sunk;
        board location;
        position row; 
        position column;
        boat aircraftCarrier = boat(5);
        boat battleShip = boat(4);
        boat cruiser = boat(3); 
        boat submarine = boat(3);
        boat destroyer = boat(2);

    public: 
        ability(){}; 
        ~ability(){};

        void attack(user name); 
        bool getSunkFlag() const; 
        void countHits(int rowLetter, int columnNum, user name);
        void CPUattack(); 
};

#endif