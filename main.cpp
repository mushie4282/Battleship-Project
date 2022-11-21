/**
 * @file main.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief user i/o file to play battleship 
 * @version 0.1
 * @date 2022-10-26 
 */
#include <iostream>
#include "player.h" // user input

using namespace std; 

int main()
{	
    Player me; 
    me.whoGoesFirst(); 

    cout << me.getFlag() << endl; 

    cout << "END OF PROGRAM :)\n";
    return 0; 
}