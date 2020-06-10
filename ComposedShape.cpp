/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ComposedShape.cpp
 * Author: MacbookPro
 * 
 * Created on 06 Kasım 2018 Salı, 15:56
 */

#include "ComposedShape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "PolyLine.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;
using namespace myk;
ComposedShape::ComposedShape(int smallWidth,int smallHeight,int mainWidth,int mainHeight,ofstream& myfile,int Ms,int Ss){
        
    MainShape=Ms;
    SmallShape=Ss;
    R.setRectangleWidth(mainWidth);
    R.setRectangleHeight(mainHeight);
    r.setRectangleWidth(smallWidth);
    r.setRectangleHeight(smallHeight);
    optimalFit(Ms,Ss);
    draw(Ms,Ss,myfile); 
        
}
ComposedShape::ComposedShape(int x,int y,int z,ofstream& myfile,int Ms,int Ss){
    MainShape=Ms;
    SmallShape=Ss;
    if(Ms==2 && Ss==1){
        
        T.setTriangleLenght(z);
        r.setRectangleWidth(x);
        r.setRectangleHeight(y);

        
    }
    else if(Ms==3 && Ss==1){
        
        C.setCircleRadius(z);
        r.setRectangleWidth(x);
        r.setRectangleHeight(y);

        
    }
    else if(Ms==1 && Ss==2){
        
        t.setTriangleLenght(x);
        R.setRectangleWidth(y);
        R.setRectangleHeight(z);

        
    }
    else if(Ms==1 && Ss==3){
        
        c.setCircleRadius(x);
        R.setRectangleWidth(y);
        R.setRectangleHeight(z);
        
    }
    
    optimalFit(Ms,Ss);    
    draw(Ms,Ss,myfile);    
    
}
ComposedShape::ComposedShape(int x,int y,ofstream& myfile,int Ms,int Ss){
    MainShape=Ms;
    SmallShape=Ss;
    if(Ms==2 && Ss==2){
        
        t.setTriangleLenght(x);
        T.setTriangleLenght(y);

    }
    else if(Ms==2 && Ss==3){
        
        c.setCircleRadius(x);
        T.setTriangleLenght(y);
        
    }
    else if(Ms==3 && Ss==2){
        
        t.setTriangleLenght(x);
        C.setCircleRadius(y);
        
    }
    else if(Ms==3 && Ss==3){
        
        c.setCircleRadius(x);
        C.setCircleRadius(y);
        
    }
    optimalFit(Ms,Ss);
    draw(Ms,Ss,myfile);    
   
}

void ComposedShape::optimalFit(int Ms, int Ss){
    
    stringstream buffer;
    
    if(Ms==1 && Ss==1){                       

        for(int i=0;i<R.getRectangleWidth()/r.getRectangleWidth();i++){
        
            for(int j=0;j<R.getRectangleHeight()/r.getRectangleHeight();j++){            


                buffer << "<rect x=\""<<i*r.getRectangleWidth()<<"\" y=\""<<j*r.getRectangleHeight()<<"\" width=\""<<r.getRectangleWidth()<<"\" height=\""<<r.getRectangleHeight()<<"\"  fill=\"blue\" stroke-width=\"2\" stroke=\"pink\" />\n";
                r.setPosition(buffer.str());
                r.getX()[0]=i*r.getRectangleWidth();
                r.getY()[0]=j*r.getRectangleHeight();
                r.getX()[1]=(i+1)*r.getRectangleWidth();
                r.getY()[1]=j*r.getRectangleHeight();
                r.getX()[2]=i*r.getRectangleWidth();
                r.getY()[2]=(j+1)*r.getRectangleHeight();
                r.getX()[3]=(i+1)*r.getRectangleWidth();
                r.getY()[3]=(j+1)*r.getRectangleHeight();
                buffer.str("");
                Polygon temp(r);
                vS.push_back(temp);

            }
        
        }
        
    } 
    else if(Ms==2 && Ss==1){

        double t=sqrt((T.getTriangleLenght()*T.getTriangleLenght())-(T.getTriangleLenght()/2)*(T.getTriangleLenght()/2));
    
        //Ucgenin icine ortadan baslayip sigacak kadar kucuk dortgenler cizer

        for(double i=0;i<t/r.getRectangleHeight();i++){

            for(double j=i;j<((T.getTriangleLenght()-2*r.getRectangleHeight())/r.getRectangleWidth())-1;j++){
              
                buffer << "<rect x=\""<<(j+1)*r.getRectangleWidth() -i*(r.getRectangleWidth()-r.getRectangleHeight()/sqrt(3))<<"\" y=\""<<i*r.getRectangleHeight()<<"\" width=\""<<r.getRectangleWidth()<<"\" height=\""<<r.getRectangleHeight()<<"\"  fill=\"blue\" stroke-width=\"2\" stroke=\"pink\" />\n";
                r.setPosition(buffer.str());
                r.getX()[0]=(j+1)*r.getRectangleWidth() -i*(r.getRectangleWidth()-r.getRectangleHeight()/sqrt(3));
                r.getY()[0]=i*r.getRectangleHeight();
                r.getX()[1]=(j+2)*r.getRectangleWidth() -i*(r.getRectangleWidth()-r.getRectangleHeight()/sqrt(3));
                r.getY()[1]=i*r.getRectangleHeight();
                r.getX()[2]=(j+1)*r.getRectangleWidth() -i*(r.getRectangleWidth()-r.getRectangleHeight()/sqrt(3));
                r.getY()[2]=(i+1)*r.getRectangleHeight();
                r.getX()[3]=(j+2)*r.getRectangleWidth() -i*(r.getRectangleWidth()-r.getRectangleHeight()/sqrt(3));
                r.getY()[3]=(i+1)*r.getRectangleHeight();
                buffer.str("");
                Polygon temp(r);
                vS.push_back(temp);

            }
        
        }
    }
    else if(Ms==3 && Ss==1){
    
        double temp=0,sh=0,sw=0;
        sh=r.getRectangleHeight();
        sw=r.getRectangleWidth();
        //dortgenin uzun tarafini yatay alir
        if(r.getRectangleHeight()>r.getRectangleWidth()){
            temp=sh;
            sh=sw;
            sw=temp;
        }
    
    //Dairenin icine tepeden baslayip sigacak kadar kucuk dortgenler cizer

    
        for(int i=0;i<(C.getCircleRadius()/sw);i++){
            for(int j=i;j<C.getCircleRadius()*2/sh-i;j++){

                buffer << "<rect x=\""<<C.getCircleRadius()-(sw/2+i*sw)<<"\" y=\""<<j*sh<<"\" width=\""<<sw<<"\" height=\""<<sh<<"\"  fill=\"green\" stroke-width=\"2\" stroke=\"pink\" />\n";
                r.setPosition(buffer.str());
                r.getX()[0]=C.getCircleRadius()-(sw/2+i*sw);
                r.getY()[0]=j*sh;
                r.getX()[1]=C.getCircleRadius()-(sw/2+i*sw)+sh;
                r.getY()[1]=j*sh;
                r.getX()[2]=C.getCircleRadius()-(sw/2+i*sw);
                r.getY()[2]=(j+1)*sh;
                r.getX()[3]=C.getCircleRadius()-(sw/2+i*sw)+sh;
                r.getY()[3]=(j+1)*sh;
                buffer.str("");  
                Polygon temp(r);
                vS.push_back(temp);

            }

        }
        for(int i=1;i<(C.getCircleRadius()/sw);i++){
            for(int j=i;j<C.getCircleRadius()*2/sh-i;j++){

                buffer << "<rect x=\""<<C.getCircleRadius()+(sw*i)-(sw/2)<<"\" y=\""<<j*sh<<"\" width=\""<<sw<<"\" height=\""<<sh<<"\"  fill=\"green\" stroke-width=\"2\" stroke=\"pink\" />\n";
                r.setPosition(buffer.str());
                r.getX()[0]=C.getCircleRadius()+(sw*i)-(sw/2);
                r.getY()[0]=j*sh;
                r.getX()[1]=C.getCircleRadius()+(sw*i+1)-(sw/2);
                r.getY()[1]=j*sh;
                r.getX()[2]=C.getCircleRadius()+(sw*i)-(sw/2);
                r.getY()[2]=(j+1)*sh;
                r.getX()[3]=C.getCircleRadius()+(sw*i+1)-(sw/2);
                r.getY()[3]=(j+1)*sh;
                buffer.str("");
                Polygon temp(r);
                vS.push_back(temp);

            }
        
        }
        
    }
    
    else if(Ms==1 && Ss==2){
    
        double t1=sqrt((t.getTriangleLenght() *t.getTriangleLenght())-(t.getTriangleLenght()/2)*(t.getTriangleLenght()/2));

    //Dikdortgenin icine koseden baslayip sigacak kadar kucuk ucgenler cizer

    
        for(int i=0;i<R.getRectangleWidth()/t.getTriangleLenght();i++){


            for(int j=0;j<R.getRectangleHeight()/t1;j++){

                
                buffer << "<polyline points=\""<< t.getTriangleLenght()*i<<","<<t1*j <<" "<<t.getTriangleLenght()*(i+1)<<","<<t1*j<<" "<<(t.getTriangleLenght())*(i+1)-(t.getTriangleLenght()/2)<<","<<t1*(j+1)<<"\" fill=\"orange\"/> \n";
                t.setPosition(buffer.str());
                t.getX()[0]=t.getTriangleLenght()*i;
                t.getY()[0]=t1*j;
                t.getX()[1]=t.getTriangleLenght()*(i+1);
                t.getY()[1]=t1*j;
                t.getX()[2]=(t.getTriangleLenght())*(i+1)-(t.getTriangleLenght()/2);
                t.getY()[2]=t1*(j+1);            
                buffer.str("");  
                Polygon temp(t);
                vS.push_back(temp);
                

            }

        }
        for(int i=0;i<((R.getRectangleWidth()-(t.getTriangleLenght()/2))/t.getTriangleLenght());i++){


            for(int j=0;j<(R.getRectangleHeight()/t1);j++){

                
                buffer << "<polyline points=\""<< t.getTriangleLenght()*(i+1)-(t.getTriangleLenght()/2)<<","<<t1*(j+1) <<" "<<t.getTriangleLenght()*(i+2)-(t.getTriangleLenght()/2)<<","<<t1*(j+1)<<" "<<(t.getTriangleLenght())*(i+1)<<","<<t1*j<<"\" fill=\"orange\"/> \n";
                t.setPosition(buffer.str());
                t.getX()[0]=t.getTriangleLenght()*(i+1)-(t.getTriangleLenght()/2);
                t.getY()[0]=t1*(j+1);
                t.getX()[1]=t.getTriangleLenght()*(i+2)-(t.getTriangleLenght()/2);
                t.getY()[1]=t1*(j+1);
                t.getX()[2]=(t.getTriangleLenght())*(i+1);
                t.getY()[2]=t1*j; 
                buffer.str("");
                Polygon temp(t);             
                vS.push_back(temp);

            }

        }
        
    }
    else if(Ms==2 && Ss==2){
    
        double t2=sqrt((T.getTriangleLenght()*T.getTriangleLenght())-(T.getTriangleLenght()/2)*(T.getTriangleLenght()/2));
        double t3=sqrt((t.getTriangleLenght()*t.getTriangleLenght())-(t.getTriangleLenght()/2)*(t.getTriangleLenght()/2));

        //Ucgenin icine tepeden baslayip sigacak kadar kucuk ucgenler cizer


        for(int i=0;i<T.getTriangleLenght()/t.getTriangleLenght();i++){


            for(int j=i;j<t2/t3;j++){

               
                buffer << "<polyline points=\""<< t.getTriangleLenght()*j-i*t.getTriangleLenght()/2<<","<<t3*i <<" "<<t.getTriangleLenght()*(j+1)-i*t.getTriangleLenght()/2<<","<<t3*i<<" "<<(t.getTriangleLenght())*(j+1)-(t.getTriangleLenght()/2)-i*t.getTriangleLenght()/2<<","<<t3*(i+1)<<"\" fill=\"blue\"/> \n";
                t.setPosition(buffer.str());
                t.getX()[0]=t.getTriangleLenght()*j-i*t.getTriangleLenght()/2;
                t.getY()[0]=t3*i;
                t.getX()[1]=t.getTriangleLenght()*(j+1)-i*t.getTriangleLenght()/2;
                t.getY()[1]=t3*i;
                t.getX()[2]=(t.getTriangleLenght())*(j+1)-(t.getTriangleLenght()/2)-i*t.getTriangleLenght()/2;
                t.getY()[2]=t3*(i+1);
                buffer.str("");
                Polygon temp(t);
                vS.push_back(temp);

            }

        }

    }
    else if(Ms==3 && Ss==2){
    
        double t2=sqrt((t.getTriangleLenght()*t.getTriangleLenght())-(t.getTriangleLenght()/2)*(t.getTriangleLenght()/2));
 
    
        for(int i=0;i<(C.getCircleRadius()/t.getTriangleLenght())+1;i++){
            for(int j=0;j<i*2+1;j++){

                buffer << "<polyline points=\""<<C.getCircleRadius()-(j)*t.getTriangleLenght()+i*t.getTriangleLenght() <<","<<t2*i <<" "<<C.getCircleRadius()-t.getTriangleLenght()*(j)-t.getTriangleLenght()/2+i*t.getTriangleLenght()<<","<<t2*(i+1)<<" "<<C.getCircleRadius()-t.getTriangleLenght()*(j)+t.getTriangleLenght()/2+i*t.getTriangleLenght()<<","<<t2*(i+1)<<"\" fill=\"blue\"/> \n";
                t.setPosition(buffer.str());
                t.getX()[0]=C.getCircleRadius()-(j)*t.getTriangleLenght()+i*t.getTriangleLenght();
                t.getY()[0]=t2*i;
                t.getX()[1]=C.getCircleRadius()-t.getTriangleLenght()*(j)-t.getTriangleLenght()/2+i*t.getTriangleLenght();
                t.getY()[1]=t2*(i+1);
                t.getX()[2]=C.getCircleRadius()-t.getTriangleLenght()*(j)+t.getTriangleLenght()/2+i*t.getTriangleLenght();
                t.getY()[2]=t2*(i+1);
                buffer.str("");
                Polygon temp(t);
                vS.push_back(temp);
            }
        }
        
        for(int i=0;i<(C.getCircleRadius()/t.getTriangleLenght())+1;i++){
            for(int j=0;j<i*2+1;j++){

                buffer << "<polyline points=\""<<C.getCircleRadius()-(j)*t.getTriangleLenght()+i*t.getTriangleLenght() <<","<<C.getCircleRadius()*2-(t2*(i)) <<" "<<C.getCircleRadius()-t.getTriangleLenght()*(j)-t.getTriangleLenght()/2+i*t.getTriangleLenght()<<","<<C.getCircleRadius()*2-(t2*(i+1))<<" "<<C.getCircleRadius()-t.getTriangleLenght()*(j)+t.getTriangleLenght()/2+i*t.getTriangleLenght()<<","<<C.getCircleRadius()*2-(t2*(i+1))<<"\" fill=\"blue\"/> \n";
                t.setPosition(buffer.str());
                t.getX()[0]=C.getCircleRadius()-(j)*t.getTriangleLenght()+i*t.getTriangleLenght();
                t.getY()[0]=C.getCircleRadius()*2-(t2*(i));
                t.getX()[1]=C.getCircleRadius()-t.getTriangleLenght()*(j)-t.getTriangleLenght()/2+i*t.getTriangleLenght();
                t.getY()[1]=C.getCircleRadius()*2-(t2*(i+1));
                t.getX()[2]=C.getCircleRadius()-t.getTriangleLenght()*(j)+t.getTriangleLenght()/2+i*t.getTriangleLenght();
                t.getY()[2]=C.getCircleRadius()*2-(t2*(i+1));
                buffer.str("");
                Polygon temp(t);
                vS.push_back(temp);

            }

        }
        
    }
    
    else if(Ms==1 && Ss==3){
    
        for(int i=0;i<R.getRectangleWidth()/(c.getCircleRadius()*2);i++){
        
            for(int j=0;j<(R.getRectangleHeight()/(c.getCircleRadius()*2));j++){

                
                buffer << "<circle cx=\""<<c.getCircleRadius()*2*(i)+c.getCircleRadius()<<"\" cy=\""<<c.getCircleRadius()*2*(j)+c.getCircleRadius()<<"\" r=\""<<c.getCircleRadius()<<"\" fill=\"green\" /> \n";
                c.setPosition(buffer.str());

                        
                buffer.str("");
                Polygon temp(c);
                vS.push_back(temp);

            }
        
        }
    }
    else if(Ms==2 && Ss==3){
    
        int t2=sqrt((T.getTriangleLenght()*T.getTriangleLenght())-(T.getTriangleLenght()/2)*(T.getTriangleLenght()/2));

        //Ucgenin icine tepeden baslayip sigacak kadar kucuk daireler cizer
        for(int i=0;i<t2/(c.getCircleRadius()*2)+1;i++){
            for(int j=0;j<i;j++){

                
                buffer << "<circle cx=\""<<T.getTriangleLenght()/2-j*c.getCircleRadius()*2+(i-1)*c.getCircleRadius()<<"\" cy=\""<<t2-c.getCircleRadius()*2*(i)<<"\" r=\""<<c.getCircleRadius()<<"\" fill=\"blue\" /> \n";
                c.setPosition(buffer.str());
                buffer.str("");
                Polygon temp(c);
                vS.push_back(temp);

            }

        }
        
    }
    else if(Ms==3 && Ss==3){
    
        for(int i=0;i<C.getCircleRadius()/(c.getCircleRadius()*2);i++){
            for(int j=0;j<i*2+1;j++){

                
                buffer << "<circle cx=\""<<C.getCircleRadius()-j*c.getCircleRadius()*2+i*c.getCircleRadius()*2<<"\" cy=\""<<c.getCircleRadius()+c.getCircleRadius()*2*(i)<<"\" r=\""<<c.getCircleRadius()<<"\" fill=\"blue\" /> \n";
                c.setPosition(buffer.str());
                buffer.str("");
                Polygon temp(c);
                vS.push_back(temp);

            }
        
        }
        for(int i=0;i<C.getCircleRadius()/(c.getCircleRadius()*2);i++){
            for(int j=0;j<i*2+1;j++){

                
                buffer << "<circle cx=\""<<C.getCircleRadius()-j*c.getCircleRadius()*2+i*c.getCircleRadius()*2<<"\" cy=\""<<C.getCircleRadius()*2-c.getCircleRadius()-c.getCircleRadius()*2*(i)<<"\" r=\""<<c.getCircleRadius()<<"\" fill=\"blue\" /> \n";
                c.setPosition(buffer.str());
                buffer.str("");
                Polygon temp(c);
                vS.push_back(temp);

            }

        }
        
    }
    
}

void ComposedShape::draw(int Ms,int Ss,ofstream& myfile){
    
    if(Ms==1){
        if (myfile.is_open())
        {
            myfile << "<svg version=\"1.1\" baseProfile=\"full\" width=\""<<R.getRectangleWidth()<<"\" height=\""<<R.getRectangleHeight()<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
            myfile << "<rect width=\"100%\" height=\"100%\" fill=\"red\" /> \n";
        }
        
    }
    else if(Ms==2){
        if (myfile.is_open())
        {
            myfile << "<svg version=\"1.1\" baseProfile=\"full\" width=\""<<T.getTriangleLenght()<<"\" height=\""<<T.getTriangleLenght()<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
            myfile << "<polyline points=\"0,0 "<<T.getTriangleLenght()<<",0 "<<T.getTriangleLenght()/2<<","<<sqrt((T.getTriangleLenght()*T.getTriangleLenght())-(T.getTriangleLenght()/2)*(T.getTriangleLenght()/2))<<"\" fill=\"orange\"/> \n";
        }
    }
    else if(Ms==3){
        if (myfile.is_open())
        {
            myfile << "<svg version=\"1.1\" baseProfile=\"full\" width=\""<<C.getCircleRadius()*2<<"\" height=\""<<C.getCircleRadius()*2<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
            myfile << "<circle cx=\""<<C.getCircleRadius()<<"\" cy=\""<<C.getCircleRadius()<<"\" r=\""<<C.getCircleRadius()<<"\" fill=\"green\" /> \n";
        }
    }
    
    for(int i=0;i<vS.size();i++){
        vS[i].draw(myfile);

    }  
    cout<<vS[0];
    
    myfile << "</svg>";

    
}