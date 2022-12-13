/**
 * @file Boat.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-13
 */

#include "Boat.h"

int boat::getSpaces() const
{
    return shipSize; 
}

/// @brief if there was a hit, decrease ship size
/// @param flag 
void boat::changeShipSize(bool flag)
{
    if(flag)
    {
        --shipSize;
    }
}