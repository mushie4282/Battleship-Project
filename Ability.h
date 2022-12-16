/**
 * @file Ability.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief 
 * @version 0.1
 * @date 2022-12-15
 */

#ifndef ABILITY_H
#define ABILITY_H

#include <iostream>
#include "board.h"
#include "User.h"

class ability
{
    private:
        bool sunk;
        board location;
        position row; 
        position column;

    public: 
        ability(){}; 
        ~ability(){};

        void attack(user name); 
        bool getSunkFlag() const; 
};

#endif