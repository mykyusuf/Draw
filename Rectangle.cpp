/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rectangle.cpp
 * Author: MacbookPro
 * 
 * Created on 06 Kasım 2018 Salı, 15:56
 */

#include "Rectangle.h"

Rectangle::Rectangle() {
    width=0;
    height=0;
}

void Rectangle::setRectangleHeight(double h){
    
    height=h;
    setArea();
    setPeri();
    
}
void Rectangle::setRectangleWidth(double w){
    
    width=w;
    setArea();
    setPeri();
    
}
void Rectangle::setPosition(string s){
    pos=s;
}
    
void Rectangle::draw(ofstream& myfile){
    if (myfile.is_open())
    {
        myfile <<pos<<endl;
    }
}
bool Rectangle::operator ==(const Rectangle& d) {
        if(this->area == d.area && this->perimeter==d.perimeter) {
           return true;
        }      
         
        return false;
}
bool Rectangle::operator !=(const Rectangle& d) {
        if(this->area != d.area || this->perimeter!=d.perimeter) {
           return true;
        }      
         
        return false;
}
double* Rectangle::getX(){
        return x;
}
double* Rectangle::getY(){
        return y;
}
Rectangle Rectangle::operator+(double s) {
        Rectangle r1;
        r1.setRectangleHeight(this->height + s);
        r1.setRectangleWidth(this->width + s);
         
        return r1;
}
Rectangle Rectangle::operator-(double s) {
        Rectangle r1;
        r1.setRectangleHeight(this->height - s);
        r1.setRectangleWidth(this->width - s);
         
        return r1;
}
double Rectangle::getArea(){
        return area;
}
double Rectangle::getPeri(){
        return perimeter;
}
string Rectangle::getPosition(){
        return pos;
}
void Rectangle::setArea(){
        area=height*width;
    }
    
void Rectangle::setPeri(){
        perimeter=2*(height+width);
}