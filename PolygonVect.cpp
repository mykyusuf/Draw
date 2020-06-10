/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PolygonVect.cpp
 * Author: MacbookPro
 * 
 * Created on 23 Aralık 2018 Pazar, 18:42
 */

#include "PolygonVect.h"

PolygonVect::PolygonVect() {
}
PolygonVect::PolygonVect(const vector<Point2D> &points) {
    for(int i=0;i<points.size();i++){
            p.push_back(points[i]);
    }
    size=points.size();
}
PolygonVect::PolygonVect(const Point2D &dot) {
    p.push_back(dot);
}
PolygonVect::PolygonVect(Circle c) {
    Point2D t;
    for(int i=0;i<100;i++){
        t.x=c.getX()[i];
        t.y=c.getY()[i];   
        p.push_back(t);
    }
    area=c.getArea();
    perimeter=c.getPeri();
    size=100;
    pos=c.getPosition();
}
PolygonVect::PolygonVect(Rectangle r) {
    Point2D t;
    for(int i=0;i<4;i++){
            t.x=r.getX()[i];
            t.y=r.getY()[i]; 
            p.push_back(t);
        }
        area=r.getArea();
        perimeter=r.getPeri();        
        size=4;
        pos=r.getPosition();
}
PolygonVect::PolygonVect(Triangle t) {
    Point2D k;    
    for(int i=0;i<3;i++){
            k.x=t.getX()[i];
            k.y=t.getY()[i];        
            p.push_back(k);
    }
        area=t.getArea();
        perimeter=t.getPeri();        
        size=3;
        pos=t.getPosition();
}

