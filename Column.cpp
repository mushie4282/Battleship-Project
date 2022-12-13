/**
 * @file Column.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-12
 */

#include "Column.h"

/**
 * @brief The board's columns goes from 1 - 10
 * 
 */
void Column::setColumnNum()
{
    std::cout << "\nEnter column number: ";
    std::cin >> columnNum; 
    while(columnNum > 10)
    {
        std::cout << "Invalid colum, try again: ";
        std::cin >> columnNum; 
    }
}