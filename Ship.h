/**
 * @file player.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief user input class implementation file
 * @version 0.1
 * @date 2022-11-21
 * 
 */

#ifndef SHIP_H
#define SHIP_H

#include "Row.h"
#include "Column.h"

class Ship{
    private:
        Row row;
        Column column;

    protected:
        virtual void setLocation(Row r, Column c);

};


#endif