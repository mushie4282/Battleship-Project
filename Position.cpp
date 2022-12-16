/**
 * @file Position.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief collect row letter and column number from user
 * @version 0.1
 * @date 2022-12-12 
 */

#include "Position.h"

/**
 * @brief return the chosen column
 * 
 * @return int 
 */
int position::getColumnNum() const
{
    return columnNum; 
}

/**
 * @brief return the chosen row but as a number
 * 
 * @return int 
 */
int position::getRowLetter()
{
    char upperCaseLetter = toupper(rowLetter); // in case someone inputs a lower case letter
    // convert the letter into an applicable row number
    return upperCaseLetter - 'A' + 1; 
}

/**
 * @brief ask the user what column they want to select
 * 
 */
void position::setColumnNum()
{
    int temp; 
    std::cout << "Enter column number: ";
    std::cin >> columnNum;
    // only numbers up to 9 and no alphabet letters
    while(columnNum > 9 || isalpha(columnNum))
    {
        std::cout << "Invalid colum, try again: ";
        std::cin >> columnNum; 
    }
}

/**
 * @brief ask the user what row they want to select
 * 
 */
void position::setRowLetter()
{
    std::cout << "Enter row letter: ";
    std::cin >> rowLetter; 
    // only letters up to 'I' and no digits
    while(toupper(rowLetter) > 'I' || isdigit(rowLetter))
    {
        std::cout << "Invalid row, try again: ";
        std::cin >> rowLetter;
    }
}