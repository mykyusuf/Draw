#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include "Polygon.h"
#include "ComposedShape.h"
#include "PolyLine.h"
#include "Shape.h"

using namespace std;
using namespace myk;

ostream& operator<<(ostream& output, const Shape& x ) { 
        
        ofstream myfile("Shape.svg");
        if (myfile.is_open())
        {
            myfile<<x;
        
        }
        
        output<<"Shape.svg ye cizildi."<<endl;
        return output;
}
void printAll(vector<Shape> s){
    for(int i=0;i<s.capacity();i++){
        cout<<s[i];
    }
}
vector<Polygon> convertAll(vector<Shape> s){
    vector<Polygon> n;
    Polygon p1;
    for(int i=0;i<s.capacity();i++){
        p1.getP()->x=s[i].getP().x;
        p1.getP()->y=s[i].getP().y;
        n.push_back(p1);
    }
    return n;
}
/*
 void sortShapes(vector<Shape> s){
    vector<Shape> n;
    int j=0;
    n.push_back(s[0]);
    for(int i=1;i<s.capacity();i++){
        
        for(j=0;s[i].geta()>n[j].geta() && j<n.capacity();j++){
        }
        n.insert(n.begin()+j, s[i]);
        
        
    }

}
*/
int main(int argc, char** argv) {
    
    ofstream myfile("RESULT.svg");
    char Main,Small;
    auto hata=1;
    auto mainWidth=0,mainHeight=0,mainLenght=0,mainRadius=0,smallWidth=0,smallHeight=0,smallLenght=0,smallRadius=0;
    auto MainShapeType=0,SmallShapeType=0;
    Rectangle r1,r2;
    Circle c1,c2;
    Triangle t1,t2;
    vector<Polygon::Point2D> p;
    Polygon::Point2D point;
    
    
    
    //Assignment == denemesi Sekiller esitmi kontrol eden test
    
    r1.setRectangleHeight(100);
    r1.setRectangleWidth(100);
    r2.setRectangleHeight(100);
    r2.setRectangleWidth(110);
    c1.setCircleRadius(100);
    c2.setCircleRadius(100);
    t1.setTriangleLenght(100);
    t2.setTriangleLenght(110);
    
    if(r1==r2){
        cout<<"Dortgenler Esit! ";}
    else{
        cout<<"Dortgenler esit degil! ";
    }
    if(t1==t2){
        cout<<"Ucgenler Esit! ";}
    else{
        cout<<"Ucgenler esit degil! ";
    }
    if(c1==c2){
        cout<<"Daireler Esit! ";}
    else{
        cout<<"Daireler esit degil! ";
    }
    
    cout<<endl<<endl;
    
    //Polygon classi denemeleri
    
    r1.getX()[0]=0;
    r1.getX()[1]=10;
    r1.getX()[2]=20;
    r1.getX()[3]=30;
    r1.getY()[0]=0;
    r1.getY()[1]=10;
    r1.getY()[2]=20;
    r1.getY()[3]=20;
    
    point.x=20;
    point.y=20;
    
    t1.getX()[0]=0;
    t1.getY()[0]=0;
    t1.getX()[1]=0;
    t1.getY()[1]=10;
    t1.getX()[2]=10;
    t1.getY()[2]=10;
    
    
    //circle objesini polygona cevirme yok
    
    Polygon p1(r1),p2(c1),p3(t1),p4(p),p5(point);
    PolyLine pl(r1);
    
    //Denemek istediginizi yorumdan cikartin. Composed shape denemelerinden önce svg leri kontrol edin
    
    cout<<"polygon cizim denemesi: "<<p1<<endl;
    //cout<<p2<<endl;
    //cout<<p3<<endl;
    //cout<<p4<<endl;
    //cout<<p5<<endl;
    //cout<<pl<<endl;
    
    cout<< endl;
    
    //Operator [] denemesi
    
    cout<<"operator denemesi p1[1].x = "<<p1[1].x<<endl;
    
    
    //operator + denemesi
    
    cout<<p1.getSize()<<endl;
    p1 = p1 + p1;
    cout<<p1.getSize()<<endl;
    
    // << operator cizim denemesi
    
    cout<<r1;
    cout<<c1;
    cout<<t1;
    
    
    //Composed shape ile istenen sekillerin denenmesi. buradan sonrasi onceki odevlerde yapilan sekiller
    //Karakter kontrolu, dogru karakter girilene kadar sormaya devam eder    
    
    while(hata==1){
        cout<<"Please enter the main container shape (R,C,T)";
        cin>>Main;
        if(Main=='r'||Main=='R'){
            cout<<"Please enter the width";
            cin>>mainWidth;
            while(cin.fail()) {
            cout << "Hata! Please enter the integer width "<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> mainWidth;
            }
            
            cout<<"Please enter the height";
            cin>>mainHeight;
            while(cin.fail()) {
            cout << "Hata! Please enter the integer height "<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> mainHeight;
            }
            MainShapeType=1;
            hata=0;
        }
        else if(Main=='t'||Main=='T'){
            cout<<"Please enter the lengt of triangle";
            cin>>mainLenght;
            while(cin.fail()) {
                cout << "Hata! Please enter the integer lenght "<<endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> mainLenght;
            }
            MainShapeType=2;            
            hata=0;
        }
        else if(Main=='c'||Main=='C'){
            cout<<"Please enter the radius of circle";
            cin>>mainRadius;
            while(cin.fail()) {
                cout << "Hata! Please enter the integer radius "<<endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> mainRadius;
            }
            MainShapeType=3;            
            hata=0;
        }
        else{
            cout<<"Dogru Karakter girin!\nr";
            hata=1;
            MainShapeType=0;
        }
    }
    
    hata=1;

    while(hata==1){

        cout<<"Please enter the small shape (R,C,T)";
        cin>>Small;
        if(Small=='r'||Small=='R'){
            cout<<"Please enter the width";
            cin>>smallWidth;
            while(cin.fail()) {
                cout << "Hata! Please enter the integer width "<<endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> smallWidth;
            }
            cout<<"Please enter the height";
            cin>>smallHeight;
            while(cin.fail()) {
                cout << "Hata! Please enter the integer height "<<endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> smallHeight;
            }
            SmallShapeType=1;   
            hata=0;
        }
        else if(Small=='t'||Small=='T'){
            cout<<"Please enter the lengt of triangle";
            cin>>smallLenght;
            while(cin.fail()) {
                cout << "Hata! Please enter the integer lenght "<<endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> smallLenght;
            }
            SmallShapeType=2;
            hata=0;
        }
        else if(Small=='c'||Small=='C'){
            cout<<"Please enter the radius of circle";
            cin>>smallRadius;
            while(cin.fail()) {
                cout << "Hata! Please enter the integer radius "<<endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> smallRadius;
            }
            SmallShapeType=3;
            hata=0;
        }
        else{
            cout<<"Dogru Karakter girin!\nr";
            hata=1;
            SmallShapeType=0;
        }
        
    }
    
    if(MainShapeType==1 && SmallShapeType==1){
        ComposedShape(smallWidth,smallHeight,mainWidth,mainHeight,myfile,1,1);
    }
    if(MainShapeType==2 && SmallShapeType==1){
        ComposedShape(smallWidth,smallHeight,mainLenght,myfile,2,1);
    }
    if(MainShapeType==3 && SmallShapeType==1){
        ComposedShape(smallWidth,smallHeight,mainRadius,myfile,3,1);
    }
    if(MainShapeType==1 && SmallShapeType==2){
        ComposedShape(smallLenght,mainWidth,mainHeight,myfile,1,2);
    }
    if(MainShapeType==2 && SmallShapeType==2){
        ComposedShape(smallLenght,mainLenght,myfile,2,2);
    }
    if(MainShapeType==3 && SmallShapeType==2){
        ComposedShape(smallLenght,mainRadius,myfile,3,2);
    }
    if(MainShapeType==1 && SmallShapeType==3){
        ComposedShape(smallRadius,mainWidth,mainHeight,myfile,1,3);
    }
    if(MainShapeType==2 && SmallShapeType==3){
        ComposedShape(smallRadius,mainLenght,myfile,2,3);
    }
    if(MainShapeType==3 && SmallShapeType==3){
        ComposedShape(smallRadius,mainRadius,myfile,3,3);
    }
    cout<<"RESULT.svg ye cizildi!\n";
    myfile.close();
    
    return 0;
}
