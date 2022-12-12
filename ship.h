/**
 * @file ship.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief abstract class for all ships in the game
 * @version 0.1
 * @date 2022-11-21
 */

#ifndef SHIP_H
#define SHIP_H

#include <iostream> 
#include "board.h"


class ship
{
    private: 
        int spaces = 0; // ship size
        bool vertical; // check if it is horizontal
        // static object would be shared amongst all child classes
        board* gameBoard; // the game board should be generated

    public: 
        ship() {
            std::cout << "Create Ship\n";
            gameBoard->getUserBoard(); 
        }; 
        ~ship(){ };
        virtual void placement(int d, char a) =0;

        void setOrientation(); // whether to place the ship vertial or horizontal
        bool getOrientation() {return vertical;};
        
        void setSpaces(int s){spaces = s;}; 
        int getSpaces() {return spaces;};
        
        board* getBoard(){return gameBoard;}; // return pointer to game board
};

#endif