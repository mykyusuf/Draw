/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ComposedShape.h
 * Author: MacbookPro
 *
 * Created on 06 Kasım 2018 Salı, 15:56
 */

#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H
#include <fstream>
#include <iostream>
#include <vector>
#include "Polygon.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

using namespace std;
using namespace myk;

class ComposedShape : Shape{
public:
    ComposedShape(int smallWidth,int smallHeight,int mainWidth,int mainHeight,ofstream& myfile,int Ms,int Ss);
    ComposedShape(int x,int y,int z,ofstream& myfile,int Ms,int Ss);
    ComposedShape(int x,int y,ofstream& myfile,int Ms,int Ss);

    void optimalFit(int Ms,int Ss);
    void draw(int Ms,int Ss,ofstream& myfile);

    void operator ++(){
        
        for(int i=0;i<vS.capacity();i++){
            vS[i].getP()->x=vS[i].getP()->x + 1;
        }
        
    }
    void operator --(){
        
        for(int i=0;i<vS.capacity();i++){
            vS[i].getP()->x=vS[i].getP()->x - 1;
        }
        
    }
    double getArea(){
        return 1;
    }
    double getPeri(){
        return 0;
    }
    
private:
    Rectangle R,r;
    Circle C,c;
    Triangle T,t;
    vector<Polygon> vS;
    int MainShape,SmallShape;
    
};



#endif /* COMPOSEDSHAPE_H */

