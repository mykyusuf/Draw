/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Triangle.cpp
 * Author: MacbookPro
 * 
 * Created on 06 Kasım 2018 Salı, 15:56
 */

#include "Triangle.h"

Triangle::Triangle() {
    lenght=0;
}

void Triangle::setTriangleLenght(double l){
    
    lenght=l;
    setArea();
    setPeri();
    
}
void Triangle::setPosition(string s){
    pos=s;
}
    
void Triangle::draw(ofstream& myfile){
    if (myfile.is_open())
    {
        myfile <<pos<<endl;
    }
}
bool Triangle::operator ==(const Triangle& d) {
        if(this->area == d.area) {
           return true;
        }      
         
        return false;
}
bool Triangle::operator !=(const Triangle& d) {
        if(this->area != d.area) {
           return true;
        }      
         
        return false;
}
double* Triangle::getX(){
        return x;
}
double* Triangle::getY(){
        return y;
}
Triangle Triangle::operator+(double s) {
        Triangle t1;
        t1.setTriangleLenght(this->lenght + s);
         
        return t1;
}
Triangle Triangle::operator-(double s) {
        Triangle t1;
        t1.setTriangleLenght(this->lenght - s);
         
        return t1;
}
double Triangle::getArea(){
        return area;
}
double Triangle::getPeri(){
        return perimeter;
}
string Triangle::getPosition(){
        return pos;
}
void Triangle::setArea(){
        area=lenght*(lenght*sqrt(3))/2;
}

void Triangle::setPeri(){
        perimeter=3*lenght;
}
