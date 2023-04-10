/**
 * @file Fleet.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief user input class implementation file
 * @version 0.1
 * @date 2022-11-21
 * 
 */

#ifndef FLEET_H
#define FLEET_H

#include "AircraftCarrier.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"

class Fleet{
    private:
        AircraftCarrier aircraftcarriers;
        Battleship battleships;
        Cruiser cruisers;
        Destroyer destroyers;
        Submarine submarines;
    public:
        Fleet();

        ~Fleet();

};

#endif