/**
 * @file Shape.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief user input class implementation file
 * @version 0.1
 * @date 2022-11-21
 * 
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "Row.h"
#include "Column.h"

class Shape{

    private:
        Row row;
        Column column;

    public: 
        // functions that are set and get as labeled in lab report 
        int getArea() const;
        void setArea(int length, int width);

        // Constructors are utilized when a new variable is in type Shape
        Shape(); 
        Shape(int length, int width);
        ~Shape();

        void swapDimensions();

        // Virtual functions that the code will override
        //virtual double calcArea() const = 0; 
        //virtual void draw() const = 0;
};

#endif