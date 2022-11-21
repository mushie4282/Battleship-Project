/**
 * @file main.cpp
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief user i/o file to play battleship 
 * @version 0.1
 * @date 2022-10-26 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> // for random number generator
#include <time.h> // for psuedo random number seed


using namespace std; 

// Parameters
void whoGoesFirst(bool& flag);
string convertToUpper(string& str);
string removeWhiteSpace(string& str);

int main()
{	
    bool flag = false; 
     
    whoGoesFirst(flag);

    if(flag)
        cout << "user go first" << endl;
    else    
        cout << "computer go first" << endl;

    // string str = "-allied-power--";
    // cout << "Before: " << str << endl;
    // int num = 0; 
    // while(num > -1)
    // {
    //     num = str.find('-');

    //     str.erase(num,1);
    //     if(num == str.size())
    //     {
    //        break;
    //     }
    // }
    // cout << str << endl;
    // string temp; 
    // for(int a = 0; a < str.size(); ++a)
    // {
    //     temp += toupper(str[a]);
    // }
    // cout << "After: " << temp << endl;

    cout << "END OF PROGRAM :)\n";
    return 0; 
}

/*
* The first turn is determined by answering a randomized history question about WWI. 
* If the player answers correctly, the player will be first to play. 
* Otherwise, computer will make its first move.
*/ 
void whoGoesFirst(bool& flag)
{
    vector<string> decideUser;
    vector<string> checkUser;
    string userAnswer, userAnswerEditA, userAnswerEditB;
    string question, answer;
    ifstream in, input; 
    in.open("WW1questions.txt");
    input.open("WW1answer.txt");
    
    // collect WWI questions and associated answer from external files
    if(!(in.is_open()) || !(input.is_open()))
    {
        std::cout << "Could not one open file" << endl;
        exit(0); 
    }
    else
    {
        while (getline(in,question) && getline(input,answer))
        {
            checkUser.push_back(answer);
            decideUser.push_back(question);
        }
    }

    srand(time(0));
    int num = rand() % (3 - 0 + 1);

    // display to console and get user's input
    cout << "Welcome to BATTLESHIP game!\n";
    cout << "Answer a World War I question to see who goes first.\n";
    cout << decideUser.at(num) << endl;
    getline(cin,userAnswer); 
    // remove white spaces in the answer;
    userAnswerEditA = removeWhiteSpace(userAnswer);
    // conver any answer into all uppercase letters to compare with database answer
    userAnswerEditB = convertToUpper(userAnswerEditA);

    // check if the user's answer matches the database answer
    if(checkUser.at(num) == userAnswerEditB)
    {
        flag = true; 
    }
    else
    {
        flag = false; 
    }

}

/// @brief convert all letters in the string into uppercase. 
/// @param str 
/// @return a string that contains all capital letters
string convertToUpper(string& str)
{
    string temp;
    //convert each char to uppercase
    for(int i = 0; i < str.size(); ++i)
    {
        temp += toupper(str[i]);
    }
    return temp;
}

/// @brief remove any white space in the string
/// @param str 
/// @return a string that contains only letters/characters
string removeWhiteSpace(string& str)
{
    string temp = str; 
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