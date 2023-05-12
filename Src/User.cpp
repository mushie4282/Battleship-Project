/**
 * @file user.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief decide who goes first and holds the number of boats a user has
 * @version 0.1
 * @date 2022-11-21
 * 
 */
#include "User.h"

/****************** These functions are for whoGoesFirst() *******************/
/// @brief convert all letters in the std::string into uppercase. 
/// @param str 
/// @return a string that contains all capital letters
std::string user::convertToUpper(std::string& str)
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
/// @return a string that contains only letters/characters
std::string user::removeWhiteSpace(std::string& str)
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
/****************** End of functions for whoGoesFirst() *******************/

/**
 * @brief Quiz the user a WWI question to decide if the user will attack first
 * 
 * @return * void 
 */
void user::whoGoesFirst()
{
    std::string userAnswer, userAnswerEditA, userAnswerEditB;
    std::string question, answer;
    std::ifstream in, input; 
    in.open("WW1questions.txt");
    input.open("WW1answer.txt");
    
    // collect WWI questions and associated answer from external files
    if(!(in.is_open()) || !(input.is_open()))
    {
        std::cout << "Could not one open file\n";
        std::cout << "Program Ends\n";
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
    std::cout << "Answer a World War I question to see who goes first.\n";
    std::cout << decideUser.at(num) << std::endl;
    std::getline(std::cin,userAnswer);
    
    // remove white spaces in the answer;
    userAnswerEditA = removeWhiteSpace(userAnswer);
    // conver answer into all uppercase letters to compare with database answer
    userAnswerEditB = convertToUpper(userAnswerEditA);

    // check if the user's answer matches the database answer
    if(checkUser.at(num) == userAnswerEditB)
    {
        userFirst = true; 
    }
    else
    {
        userFirst = false; 
    }

}

/**
 * @brief decision flag of who start attcking in the main game loop
 * 
 * @return true user attacks first
 * @return false CPU attacks first
 */
bool user::getUserFirst()
{
    return userFirst; 
}

/**
 * @brief subtract the number of ships in possion when flag = 1
 * 
 * @param flag an entire ship has been sunk
 */
void user::decrementBoatNum(bool flag)
{
    if(flag)
    {
        --boat; 
    }
}

/**
 * @brief return the number of boat an object has
 * 
 * @return int number of boats in possession 
 */
int user::getBoatAmt()
{
    return boat; 
}