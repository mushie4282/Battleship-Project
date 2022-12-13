/**
 * @file Placement.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief 
 * @version 0.1
 * @date 2022-12-13
 */
#include "Placement.h"

/**
 * @brief Placement of the user's ships
 * 
 */
void placement::placePieces()
{
    std::cout << "Set your battlefield!\n"; 

    for(int z = 0; z < 5; ++z)
    {
        std::cout << "Ship " << z + 1 << std::endl; 
        std::cout << "Size: " << fleet[z].getSpaces() << std::endl; 
        Row.setRowLetter(); 
        Column.setColumnNum(); 
        // shape.setVerticalFlag(); 
        field.setPiece(Column.getColumnNum(), Row.getRowLetter(), fleet[z].getSpaces());
    }    
}