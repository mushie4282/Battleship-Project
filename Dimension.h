/**
 * @file Dimension.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief for size object (ship size) and shape object (horizontal/vertical)
 * @version 0.1
 * @date 2022-12-12
 */
#ifndef DIMENSION_H
#define DIMENSION_H

#include <iostream>

class dimension
{
    private:
        bool verticalFlag; 
    
    public:
        dimension()
        {
            verticalFlag = false; 
        }
        ~dimension(){}; 

        bool getVerticalFlag(); 
        void setVerticalFlag(); 
};

#endif