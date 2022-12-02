/**
 * @file Size.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief user input class implementation file
 * @version 0.1
 * @date 2022-11-21
 * 
 */

#ifndef SIZE_H
#define SIZE_H

class Size{
    private:
        int size;

    public:
        Size();
        Size(int);
        ~Size();

        void setSize(int);

};

#endif