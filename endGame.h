/**
 * @file endGame.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief this flag will be set when someone wins the game
 * @version 0.1
 * @date 2022-12-13 
 */

#ifndef ENDGAME_H
#define ENDGAME_H

class endGame
{
    private:
        bool endOfgame; // set true to end while loop in game class

    public:
        endGame(){
            endOfgame = false; 
        }; 
        ~endGame(){}; 
        void setGameFlag(bool flag); 
        bool getGameFlag() const; 
};

#endif