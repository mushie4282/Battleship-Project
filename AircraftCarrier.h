/**
 * @file Square.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief user input class implementation file
 * @version 0.1
 * @date 2022-11-21
 * 
 */

#ifndef AIRCRAFTCARRIER_H
#define AIRCRAFTCARRIER_H

#include "Square.h"
#include "Size.h"
#include "Shape.h"

class AircraftCarrier{
    private:
        Size size = 5;
        Shape shape(5,1);
        Square squares = 5;

    public:
        AircraftCarrier();
        ~AircraftCarrier();


};
#endif