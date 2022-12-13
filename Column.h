/**
 * @file Column.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef COLUMN_H
#define COLUMN_H

#include <iostream> 

class Column
{
    private:
        int columnNum; // game board column

    public: 
        Column(){}; 
        ~Column(){};

        int getColumnNum(){return columnNum;}; 
        void setColumnNum();         
};

#endif