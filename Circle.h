/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: MacbookPro
 *
 * Created on 06 Kasım 2018 Salı, 15:56
 */

#ifndef CIRCLE_H
#define CIRCLE_H
#include <fstream>
#include <iostream>

#include "Shape.h"

using namespace std;

class Circle : Shape {
public:
    Circle();
       
    inline double getCircleRadius() const {
        return radius;
    }
    void setCircleRadius(double r);    
    void setArea();    
    void setPeri();
    Circle operator+(double s);
    Circle operator-(double s);
    double getArea();
    double getPeri();
    string getPosition();
    void setPosition(string s);    
    void draw(ofstream& myfile);
    bool operator ==(const Circle& d);
    bool operator !=(const Circle& d);
    double* getX();
    double* getY();
    void operator ++(){
        
        for(int i=0;i<100;i++){
            x[i]=x[i]+1;
        }
        
    }
    void operator --(){
        
        for(int i=0;i<100;i++){
            x[i]=x[i]-1;
        }
        
    }

    friend ostream& operator<<(ostream& output, const Circle& x ) { 
        
        ofstream myfile("circle.svg");

        if (myfile.is_open())
        {
            myfile << "<svg version=\"1.1\" baseProfile=\"full\" width=\""<<x.getCircleRadius()*2<<"\" height=\""<<x.getCircleRadius()*2<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
            myfile << "<circle cx=\""<<x.getCircleRadius()<<"\" cy=\""<<x.getCircleRadius()<<"\" r=\""<<x.getCircleRadius()<<"\" fill=\"green\" /> \n";
            myfile << "</svg>";

        }
        output<<"circle.svg ye cizildi."<<endl;
        return output;
    }
    
private:
    double x[100],y[100];
    double area;
    double perimeter;
    string pos;
    double radius;
    
};

#endif /* CIRCLE_H */

