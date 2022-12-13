/**
 * @file Row.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-12
 */

#include "Row.h"

/**
 * @brief The board's rows goes from A - J
 * 
 */
void Row::setRowLetter()
{
    std::cout << "Enter row letter: ";
    std::cin >> rowLetter; 
    while(toupper(rowLetter) > 'J')
    {
        std::cout << "Invalid row, try again: ";
        std::cin >> rowLetter;
    }
}