#include<iostream>
using namespace std;
// class Mammal{
// public:
//     virtual void speak(){
//         cout<<"Mammal speak!"<<endl;
//     }
// };
// class Dog:public Mammal{
// public:
//     void speak(){
//         cout<<"Dog speak!"<<endl;
//     }
// };
// int main(){
//     Dog d1;
//     d1.speak();
//     return 0;
// }



// class BaseClass{
// public:
//     virtual void fun1(){
//         cout<<"base fun1!"<<endl;
//     }
//     void fun2(){
//         cout<<"base fun2"<<endl;
//     }

// };
// class DerivedClass:public BaseClass{
// public:
//     void fun1(){
//         cout<<"derived fun1"<<endl;
//     }
//     void fun2(){
//         cout<<"derived fun2"<<endl;
//     }
// };
// int main(){
//     BaseClass b;
//     DerivedClass d;
//     DerivedClass* pd1=&d;
//     BaseClass* pd2= &d;
//     pd1->fun1();
//     pd1->fun2();
//     pd2->fun1();
//     pd2->fun2();
//     return 0;
// }




class Point{
private:
    int x;
    int y;
public:
    Point(int a=0,int b=0):x(a),y(b) {}
    Point& operator++();
    Point operator++(int);
    friend ostream& operator<<(ostream& out,const Point& rhs);
    friend istream& operator>>(istream& in,Point& rhs);
};
Point& Point::operator++(){
    x++;
    y++;
    return *this;
};
Point Point::operator++(int){
    Point old = *this;
    x++;
    y++;
    return old;
};
ostream& operator<<(ostream& out,const Point& rhs){
    out<<rhs.x<<" "<<rhs.y;
    return out;
}
istream& operator>>(istream& in,Point& rhs){
    in>>rhs.x>>rhs.y;
    return in;
}
int main(){
    Point p;
    cout<<p<<endl;
    ++++p;
    cout<<p<<endl;
    cout<<p++<<endl;
    cout<<p<<endl;
    cin>>p;
    cout<<p<<endl;

}





// class Shape{
// public:
//     virtual ~Shape(){

//     };
//     virtual double GetArea()=0;
//     virtual double GetPerim()=0;
//     virtual int getVertexCount() const=0;
// };

// class Rectangle:public Shape{
// protected:
//     double height;
//     double width;
// public:
//     Rectangle(double a=0,double b=0):height(a),width(b){}
//     virtual ~Rectangle() {}
//     double GetArea(){
//         return height*width;
//     }
//     double GetPerim(){
//         return 2*(height+width);
//     }
//     int getVertexCount() const{
//         return 4;
//     };
// };

// class Square:public Rectangle{
// public:
//     Square(double a=0):Rectangle(a,a){}
//     double GetArea(){
//         return height*width;
//     }
//     double GetPerim(){
//         return 2*(height+width);
//     }
// };



// class Circle:public Shape{
// private:
//     static const double PI;
//     double r;
// public:
//     Circle(double a=0):r(a){}
//     double GetArea(){
//         return PI*r*r;
//     }
//     double GetPerim(){
//         return 2*PI*r;
//     }
//     int getVertexCount() const{
//         return 0;
//     };
// };
// const double Circle::PI=3.14;
// int main(){
//     Square s(1);
//     Shape* ps1=&s;
//     cout<<ps1->getVertexCount()<<endl;




//     // Square *ps2=dynamic_cast<Square*>(ps1);
//     // Square *ps2=(Square*)ps1;
//     // cout<<ps2->getVertexCount()<<endl;
//     return 0;
// }
