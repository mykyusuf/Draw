/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Polygon.cpp
 * Author: MacbookPro
 * 
 * Created on 25 Kasım 2018 Pazar, 17:55
 */

#include "Polygon.h"
#include <fstream>
using namespace myk;
Polygon::Polygon(){}

Polygon::Polygon(const vector<Point2D> &points){
        
        p=new Point2D[points.size()];
        for(int i=0;i<points.size();i++){
            p[i] = points[i];
        }
        size=points.size();
}
Polygon::Polygon(const Point2D &dot){
        
        p=new Point2D[1];
        p[0]=dot;
        size=1;
        
}
Polygon::Polygon(Circle c){
        p=new Point2D[100];   
        for(int i=0;i<100;i++){
            p[i].x=c.getX()[i];
            p[i].y=c.getY()[i];        
        }
        area=c.getArea();
        perimeter=c.getPeri();
        size=100;
        pos=c.getPosition();
}
Polygon::Polygon(Rectangle r){
        p=new Point2D[4];
        for(int i=0;i<4;i++){
            p[i].x=r.getX()[i];
            p[i].y=r.getY()[i]; 
        }
        area=r.getArea();
        perimeter=r.getPeri();        
        size=4;
        pos=r.getPosition();
}
Polygon::Polygon(Triangle t){
        p=new Point2D[3];    
        for(int i=0;i<3;i++){
            p[i].x=t.getX()[i];
            p[i].y=t.getY()[i];        
        }
        area=t.getArea();
        perimeter=t.getPeri();        
        size=3;
        pos=t.getPosition();
}

void Polygon::draw(ofstream& myfile){
    if (myfile.is_open())
    {
        myfile <<pos<<endl;
    }
}
bool Polygon::operator ==(const Polygon& d) {
        if(this->area == d.area && this->perimeter == d.perimeter) {
            return true;
            
}      
         
        return false;
}
bool Polygon::operator !=(const Polygon& d) {
        if(this->area != d.area || this->perimeter != d.perimeter) {
            return true;

        }      
         
        return false;
}
Polygon Polygon::operator+(const Polygon& b) {
        
        Polygon temp;
        temp.p =new Point2D[this->size+b.size];
        for(int i=0;i<size;i++){
            temp.p[i]=p[i];
        }
        for(int j=size;j<this->size+b.size;j++){
            temp.p[j]=b.p[j];
        }
        temp.size=this->size+b.size;
        return temp;
    
}
Polygon::Point2D Polygon::operator[](int i) {
        return p[i];
    }
int Polygon::getSize() const{
        return size;
}
Polygon::Point2D* Polygon::getP() const{
        return p;

}