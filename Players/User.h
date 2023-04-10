/**
 * @file User.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief decide who goes first and holds the number of boats a user has
 * @version 0.1
 * @date 2022-11-21
 * 
 */
#ifndef USER_H
#define USER_H

#include "User.h"
#include <iostream>
#include <fstream> // extract WW1 questions and answers
#include <string>
#include <vector> // holds all the qustions
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

class user
{
    private:
        std::vector<std::string> decideUser;// WW1 questions
        std::vector<std::string> checkUser; // WW1 answers
        bool userFirst;
        int boat; // number of ships that posses on the board
       
        // these functions are used within whoGoesFirst()
        std::string convertToUpper(std::string& str);
        std::string removeWhiteSpace(std::string& str);

    public: 
        user() {
            userFirst = false;
            boat = 5; 
        }; 
        ~user() {}; 

        void whoGoesFirst();
        bool getUserFirst();
        void decrementBoatNum(bool flag);
        int getBoatAmt();  

};

#endif