/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shape.h
 * Author: MacbookPro
 *
 * Created on 23 Aralık 2018 Pazar, 17:52
 */

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    Shape();
    class Point2D{
    public:
        double x,y;
    };
    virtual double getArea()=0;
    virtual double getPeri()=0;

    virtual void operator ++()=0;
    virtual void operator --()=0;
    Point2D getP(){
        return p;
    }
    double geta(){
        return area;
    }
private:
    Point2D p;
    double area;
    int size;
    double perimeter;
};

#endif /* SHAPE_H */

