/**
 * @file ship.cc
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief Implementation of all ship functions
 * @version 0.1
 * @date 2022-12-05
 */

#include <iostream>
#include "ship.h"
#include "AircraftCarrier.h"

/*************** SHIP *****************/
void ship::setOrientation()
{
    char input; // user input
    char updatedInput;
    std::cout << "Hortizonal(H) or Vertical(V) ?: ";
    std::cin >> input;
    updatedInput = toupper(input);

    if(updatedInput == 'H')
    {
        vertical = false; 
    }
    if(updatedInput == 'V')
    {
        vertical = true; 
    }
}
// void ship::setOrientation()
// {
//     char input; // user input
//     char updatedInput;
//     std::cout << "Hortizonal(H) or Vertical(V) ?: ";
//     std::cin >> input;
//     updatedInput = toupper(input);

//     // if input does not equal H or V
//     while(!(!(updatedInput!= 'H') || !(updatedInput != 'V'))) // while input is NOT valid
//     {
//         std::cout << "Invalid Input....\n";
//         std::cout << "Hortizonal(H) or Vertical(V) ?: ";
//         std::cin >> input; 
//         updatedInput = toupper(input);
//     }

//     orientation = updatedInput;
// }
/***************** END OF SHIP *****************/


