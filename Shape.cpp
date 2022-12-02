/**
 * @file player.h
 * @author Michelle Tran, Stephanic Vaca, Kyle Kiyuna
 * @brief user input class implementation file
 * @version 0.1
 * @date 2022-11-21
 * 
 */

#include "Shape.h"

int Shape::getArea() const{
    return row.getRow()*column.getColumn();
}

void Shape::setArea(int length, int width){
    row.setRow(length);
    column.setColumn(width);
}

Shape::Shape(){
    length = 0;
    width = 0;
}

Shape::Shape(int length, int width){
    this->length = length;
    this->width = width;
}