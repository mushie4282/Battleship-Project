/**
 * @file Square.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief user input class implementation file
 * @version 0.1
 * @date 2022-11-21
 * 
 */

#ifndef ROW_H
#define ROW_H

#include "Square.h"

class Row{
    private:
        Square squares;
    public:
        int getRow();
        void setRow(Square length);

};

#endif