/**
 * @file Dimension.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief place the ship vertical or horizontal 
 * @version 0.1
 * @date 2022-12-12
 */

#include "Dimension.h"

/**
 * @brief return whether the user wants to place the ship vertical or horizontal 
 * 
 * @return true 
 * @return false 
 */
bool dimension::getVerticalFlag()
{
    return verticalFlag; 
}

/**
 * @brief ask the user how they want to position the ships
 * 
 */
void dimension::setVerticalFlag()
{
    char input; // user input
    char updatedInput;
    std::cout << "Hortizonal(H) or Vertical(V) ?: ";
    std::cin >> input;
    updatedInput = toupper(input);

    if(updatedInput == 'H')
    {
        verticalFlag = false; 
    }
    if(updatedInput == 'V')
    {
        verticalFlag = true; 
    }
}