/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.cpp
 * Author: MacbookPro
 * 
 * Created on 06 Kasım 2018 Salı, 15:56
 */

#include "Circle.h"

Circle::Circle() {
    radius=0;
}
void Circle::setCircleRadius(double r){
    
    radius=r;
    setArea();
    setPeri();
    
}
void Circle::setPosition(string s){
    pos=s;
}
    
void Circle::draw(ofstream& myfile){
    if (myfile.is_open())
    {
        myfile <<pos<<endl;
    }
}
void Circle::setArea(){
        area=(3.14)*radius*radius;
    }
    
void Circle::setPeri(){
        perimeter=2*(3.14)*radius;
}

double Circle::getArea(){
        return area;
}
double Circle::getPeri(){
        return perimeter;
}
string Circle::getPosition(){
        return pos;
}
bool Circle::operator ==(const Circle& d) {
        if(this->area == d.area) {
           return true;
        }      
         
        return false;
}
bool Circle::operator !=(const Circle& d) {
        if(this->area != d.area) {
           return true;
        }      
         
        return false;
}
double* Circle::getX(){
        return x;
}
double* Circle::getY(){
        return y;
}
Circle Circle::operator+(double s) {
        Circle c1;
        c1.setCircleRadius(this->radius + s);
         
        return c1;
}
Circle Circle::operator-(double s) {
        Circle c1;
        c1.setCircleRadius(this->radius - s);
         
        return c1;
}