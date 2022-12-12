/**
 * @file AircraftCarrier.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief 
 * @version 0.1
 * @date 2022-12-05
 */
#ifndef AIRCRAFTCARRIER_H
#define AIRCRAFTCARRIER_H

#include <iostream> 
#include "ship.h"


class AircraftCarrier :  public ship
{
    private:  
        board* userBoard; // be able to access the board
        char piece = 'A';

    public: 
        AircraftCarrier() {
            setSpaces(5); // ship size
            userBoard = getBoard(); // get board from parent class (ship)
            std::cout << "Create Aircraft Carrier\n";
        }; 
        ~AircraftCarrier() {}; 

        void placement(int d, char a); 
};

#endif