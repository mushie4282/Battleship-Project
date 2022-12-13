/**
 * @file Row.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief 
 * @version 0.1
 * @date 2022-12-12 
 */

#ifndef ROW_H
#define ROW_H

#define SIZE 11

#include <iostream>

class Row
{
    private:
        char rowLetter; // game board row

    public: 
        Row(){}; 
        ~Row(){}; 

        void setRowLetter(); 
        char getRowLetter(){return rowLetter;};
};

#endif