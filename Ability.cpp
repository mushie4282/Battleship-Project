/**
 * @file Ability.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief 
 * @version 0.1
 * @date 2022-12-15 
 */

#include "Ability.h"

/**
 * @brief choose location to attack
 *        - board::location is using a boarch class function
 */
void ability::attack(user name)
{
    // collect attack coordinate
    std::cout << "Choose coordinates to attack:\n"; 
    row.setRowLetter(); 
    column.setColumnNum();  
    sunk = location.attack(row.getRowLetter(), column.getColumnNum(), name);
}

bool ability::getSunkFlag() const
{
    return sunk; 
}