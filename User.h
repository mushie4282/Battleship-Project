/**
 * @file User.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief user input class
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
#include <cstdlib> // for random number generator
#include <time.h> // for psuedo random number seed

class user
{
    private:
        std::vector<std::string> decideUser;// WW1 questions
        std::vector<std::string> checkUser; // WW1 answers
       
        // these functions are used within whoGoesFirst()
        std::string convertToUpper(std::string& str);
        std::string removeWhiteSpace(std::string& str);

    public: 
        user() {
             
        }; 
        ~user() {

        }; 

        bool whoGoesFirst();

};

#endif