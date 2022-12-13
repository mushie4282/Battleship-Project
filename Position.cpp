/**
 * @file Position.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-12 
 */

#include "Position.h"

int position::getColumnNum() const
{
    return columnNum; 
}
int position::getRowLetter()
{
    char upperCaseLetter = toupper(rowLetter); // in case someone inputs a lower case letter
    int row = upperCaseLetter - 'A' + 1; // convert the letter into an applicable row number
    return row; 
}

/// @brief columns goes from 1 - 9
void position::setColumnNum()
{
    int temp; 
    std::cout << "Enter column number: ";
    std::cin >> columnNum;
    while(columnNum > 9 || isalpha(columnNum))
    {
        std::cout << "Invalid colum, try again: ";
        std::cin >> columnNum; 
    }
}
/// @brief rows goes from A - I
void position::setRowLetter()
{
    std::cout << "Enter row letter: ";
    std::cin >> rowLetter; 
    while(toupper(rowLetter) > 'I' || isdigit(rowLetter))
    {
        std::cout << "Invalid row, try again: ";
        std::cin >> rowLetter;
    }
}