/**
 * @file Dimension.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief 
 * @version 0.1
 * @date 2022-12-12
 */

#include "Dimension.h"

bool dimension::getVerticalFlag()
{
    return verticalFlag; 
}

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