/**
 * @file endGame.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief 
 * @version 0.1
 * @date 2022-12-13
 */

#include "endGame.h"

void endGame::setGameFlag(bool flag)
{
    endOfgame = flag; 
}

bool endGame::getGameFlag() const
{
    return endOfgame; 
}