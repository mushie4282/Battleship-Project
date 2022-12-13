/**
 * @file main.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief user i/o file to play battleship 
 * @version 0.1
 * @date 2022-10-26 
 */
#include <iostream>
#include "Game.h"
using namespace std;

int main()
{	 
    game test1; 
    test1.gamePlay(); 
    
    cout << "\nEnd of program :)\n";
    return 0; 
}

/**
 * @brief Notes on pointer arithmetic
 * 
 * we can access any element arr[i][j] of the array using the pointer expression *(*(arr + i) + j)
 * 
    int arr[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    int (*ptr)[4] = arr; 

    for(int a = 0; a < 3; ++a)
    {
        for(int b = 0; b < 4; ++b)
        {
            // both print the same array
            cout << *(*(ptr + a) + b) << " ";
            cout << arr[a][b] << " ";
        }
        cout << endl; 
    }
 */