/**
 * @file Position.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief collect row letter and column number from user
 * @version 0.1
 * @date 2022-12-12
 */

#ifndef POSITION_H
#define POSITION_H

#include <iostream>

class position
{
    private:
        int columnNum; 
        char rowLetter; 

    public:
        position(){}; 
        ~position(){};

        void setRowLetter(); 
        int getRowLetter();

        int getColumnNum() const; 
        void setColumnNum();  
};

#endif