/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PolyLine.h
 * Author: MacbookPro
 *
 * Created on 26 Kasım 2018 Pazartesi, 22:14
 */

#ifndef POLYLINE_H
#define POLYLINE_H
#include "Polygon.h"
using namespace myk;

class PolyLine : public Polygon{
public:
    using Polygon::Polygon;
    
    friend ostream& operator<<(ostream& output, const PolyLine& x ) { 
        
        ofstream myfile("PolyLine.svg");
        if (myfile.is_open())
        {
            myfile << "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
            myfile << "<polyline points=\"";
                    
            for(int i=0;i<x.getSize();i++){
                myfile<<x.getP()[i].x<<","<<x.getP()[i].y<<" ";
            }
                    
            myfile<<"\" style=\"fill:none;stroke:black;stroke-width:3\" fill=\"orange\"/> \n";
            myfile << "</svg>";
        
        }
        
        output<<"PolyLine.svg ye cizildi."<<endl;
        return output;
    }
};

#endif /* POLYLINE_H */

