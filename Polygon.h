/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Polygon.h
 * Author: MacbookPro
 *
 * Created on 25 Kasım 2018 Pazar, 17:55
 */

#ifndef POLYGON_H
#define POLYGON_H
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <vector>

using namespace std;

namespace myk{
    
class Polygon : Shape{
public:
    
    class Point2D{
    public:
        double x,y;
    };
    Polygon();
    
    Polygon(const vector<Point2D> &points);
    Polygon(const Point2D &dot);
    Polygon(Circle c);
    Polygon(Rectangle r);
    Polygon(Triangle t);
    void operator ++(){
        
        for(int i=0;i<size;i++){
            p[i].x += 1;
        }
        
    }
    void operator --(){
        
        for(int i=0;i<size;i++){
            p[i].x -= 1;
        }
        
    }
    double getArea(){
        return area;
    }
    double getPeri(){
        return perimeter;
    }
    
    friend ostream& operator<<(ostream& output, const Polygon& x ) { 
        
        ofstream myfile("Polygon.svg");
        if (myfile.is_open())
        {
            myfile << "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
            myfile << "<polyline points=\"";
                    
            for(int i=0;i<x.size;i++){
                myfile<<x.p[i].x<<","<<x.p[i].y<<" ";
            }
                    
            myfile<<"\" fill=\"orange\"/> \n";
            myfile << "</svg>";
        
        }
        
        output<<"Polygon.svg ye cizildi."<<endl;
        return output;
    }
    
    void draw(ofstream& myfile);
    bool operator ==(const Polygon& d);
    bool operator !=(const Polygon& d);
    Polygon operator+(const Polygon& b);
    
    Point2D operator[](int i);
    int getSize() const;
    Point2D* getP() const;

private:
    Point2D *p;    
    string pos;
    int size;    
    double area;
    double perimeter;

};
}
#endif /* POLYGON_H */

