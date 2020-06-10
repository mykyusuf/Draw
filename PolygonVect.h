/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PolygonVect.h
 * Author: MacbookPro
 *
 * Created on 23 Aralık 2018 Pazar, 18:42
 */

#ifndef POLYGONVECT_H
#define POLYGONVECT_H
#include "Polygon.h"
using namespace myk;

class PolygonVect : Polygon{
public:
    PolygonVect(const vector<Point2D> &points);
    PolygonVect(const Point2D &dot);
    PolygonVect(Circle c);
    PolygonVect(Rectangle r);
    PolygonVect(Triangle t);
    PolygonVect();
    Polygon operator+(const Polygon& b){
        for(int i=0;i<b.getSize();i++){
            p.push_back(b.getP()[i]);
        }
        return p;
    }

private:
    vector<Point2D> p;
    string pos;
    int size;    
    double area;
    double perimeter;
};

#endif /* POLYGONVECT_H */

