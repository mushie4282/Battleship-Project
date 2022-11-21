/**
 * @file player.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief user input class implementation file
 * @version 0.1
 * @date 2022-11-21
 * 
 */
#include "player.h"
#include <iostream>
#include <fstream> // extract WW1 questions and answers
#include <string>
#include <vector> // holds all the qustions
#include <cstdlib> // for random number generator
#include <time.h> // for psuedo random number seed


/// @brief convert all letters in the std::string into uppercase. 
/// @param str 
/// @return a std::string that contains all capital letters
std::string Player::convertToUpper(std::string& str)
{
    std::string temp;
    //convert each char to uppercase
    for(int i = 0; i < str.size(); ++i)
    {
        temp += toupper(str[i]);
    }
    return temp;
}

/// @brief remove any white space in the std::string
/// @param str 
/// @return a std::string that contains only letters/characters
std::string Player::removeWhiteSpace(std::string& str)
{
    std::string temp = str; 
    int indexOfWhiteSpace = temp.find(' ');
    while(indexOfWhiteSpace != -1)
    {
        temp.erase(indexOfWhiteSpace,1);
        indexOfWhiteSpace = temp.find(' ');
        if(indexOfWhiteSpace == str.size())
        {
            temp.erase(indexOfWhiteSpace,1);
            return temp;
        }
    }
    return temp; 
}

/*
* The first turn is determined by answering a randomized history question about WWI. 
* If the player answers correctly, the player will be first to play. 
* Otherwise, computer will make its first move.
*/ 
void Player::whoGoesFirst()
{
    std::string userAnswer, userAnswerEditA, userAnswerEditB;
    std::string question, answer;
    std::ifstream in, input; 
    in.open("WW1questions.txt");
    input.open("WW1answer.txt");
    
    // collect WWI questions and associated answer from external files
    if(!(in.is_open()) || !(input.is_open()))
    {
        std::cout << "Could not one open file" << std::endl;
        exit(0); 
    }
    else
    {
        while (getline(in,question) && getline(input,answer))
        {
            checkUser.push_back(answer); // answer vector
            decideUser.push_back(question); // question vector
        }
    }

    // generate random number from 0 - 3
    srand(time(0));
    int num = rand() % (3 - 0 + 1);

    // display to console and get user's input
    std::cout << "Welcome to BATTLESHIP game!\n";
    std::cout << "Answer a World War I question to see who goes first.\n";
    std::cout << decideUser.at(num) << std::endl;
    std::getline(std::cin,userAnswer); 
    // remove white spaces in the answer;
    userAnswerEditA = removeWhiteSpace(userAnswer);
    // conver any answer into all uppercase letters to compare with database answer
    userAnswerEditB = convertToUpper(userAnswerEditA);

    // check if the user's answer matches the database answer
    if(checkUser.at(num) == userAnswerEditB)
    {
        Flag = true; 
    }
    else
    {
        Flag = false; 
    }

}

