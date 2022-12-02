/**
 * @file Square.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief user input class implementation file
 * @version 0.1
 * @date 2022-11-21
 * 
 */

#ifndef SQUARE_H
#define SQUARE_H

#include "Row.h"
#include "Column.h"

class Square{
    private:
        int size;

    public:
        Square();

        Square(int size);

        ~Square();

        int getSquare();

        void setSquare();

};

#endif