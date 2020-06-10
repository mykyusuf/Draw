/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Triangle.h
 * Author: MacbookPro
 *
 * Created on 06 Kasım 2018 Salı, 15:56
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <fstream>
#include <iostream>
#include <math.h>

#include "Shape.h"

using namespace std;

class Triangle : Shape{
public:
    Triangle();
    
    inline double getTriangleLenght() const{
        return lenght;
    }
    void setTriangleLenght(double l);
    void setArea();
    void setPeri();        
    Triangle operator+(double s);
    Triangle operator-(double s);
    double getArea();
    double getPeri();
    string getPosition();
    void setPosition(string s);    
    void draw(ofstream& myfile);    
    bool operator ==(const Triangle& d);
    bool operator !=(const Triangle& d);
    double* getX();
    double* getY();
    void operator ++(){
        
        for(int i=0;i<3;i++){
            x[i]=x[i]+1;
        }
        
    }
    void operator --(){
        
        for(int i=0;i<3;i++){
            x[i]=x[i]-1;
        }
        
    }

    friend ostream& operator<<(ostream& output, const Triangle& x ) { 
        
        ofstream myfile("triangle.svg");
        if (myfile.is_open())
        {
            myfile << "<svg version=\"1.1\" baseProfile=\"full\" width=\""<<x.getTriangleLenght()<<"\" height=\""<<x.getTriangleLenght()<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
            myfile << "<polyline points=\"0,0 "<<x.getTriangleLenght()<<",0 "<<x.getTriangleLenght()/2<<","<<sqrt((x.getTriangleLenght()*x.getTriangleLenght())-(x.getTriangleLenght()/2)*(x.getTriangleLenght()/2))<<"\" fill=\"orange\"/> \n";
            myfile << "</svg>";
        
        }
        
        output<<"triangle.svg ye cizildi."<<endl;
        return output;
    }
 
private:
    double x[3],y[3];
    double area;
    double perimeter;
    string pos;
    double lenght;
    

};

#endif /* TRIANGLE_H */

