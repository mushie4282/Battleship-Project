/**
 * @file spaces.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief keep track of coordinates
 * @version 0.1
 * @date 2022-12-15 
 */
#ifndef SPACES_H
#define SPACES_H

#include <vector> 

class spaces
{
    private:
        static std::vector<int> rowVec; 
        static std::vector<int> columnVec;

    public:
        spaces(){};
        ~spaces(){}; 

        void recordCoordinates(int row, int column);
        int getRowVec(int index) const; 
        int getColumnVec(int index) const; 
};

#endif