/**
 * @file Position.h
 * @author
 * @brief 
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