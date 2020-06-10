/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rectangle.h
 * Author: MacbookPro
 *
 * Created on 06 Kasım 2018 Salı, 15:56
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <fstream>
#include <iostream>

#include "Shape.h"

using namespace std;

class Rectangle : Shape {
public:
    Rectangle();    
        
    inline double getRectangleWidth() const {
        return width;
    }
    inline double getRectangleHeight() const{
        return height;
    }
    void setRectangleWidth(double w);
    void setRectangleHeight(double h);    
    void setArea();
    void setPeri();
    Rectangle operator+(double s);
    Rectangle operator-(double s);
    double getArea();
    double getPeri();
    string getPosition();
    void setPosition(string s);
    void draw(ofstream& myfile);    
    bool operator ==(const Rectangle& d);
    bool operator !=(const Rectangle& d);
    double* getX();
    double* getY();
    void operator ++(){
        
        for(int i=0;i<4;i++){
            x[i]=x[i]+1;
        }
        
    }
    void operator --(){
        
        for(int i=0;i<4;i++){
            x[i]=x[i]-1;
        }
        
    }

    friend ostream& operator<<(ostream& output, const Rectangle& x ) { 
        
        ofstream myfile("rectangle.svg");

        if (myfile.is_open())
        {
            myfile << "<svg version=\"1.1\" baseProfile=\"full\" width=\""<<x.getRectangleWidth()<<"\" height=\""<<x.getRectangleHeight()<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
            myfile << "<rect width=\"100%\" height=\"100%\" fill=\"red\" /> \n";
            myfile << "</svg>";
            
        }
        output<<"rectangle.svg ye cizildi."<<endl;
        return output;
    }

private:
    double x[4],y[4];
    double area;
    double perimeter;
    string pos;
    double width;
    double height;

};

#endif /* RECTANGLE_H */

