#include<iostream>
#include<memory>
using namespace std;
// struct Base1{float x;};
// struct Base2{float y;};
// struct Derived:Base1,Base2{};

// float main(){
//     Derived*  pd=new Derived;

//     pd->x=1;pd->y=2.0f;

//     //错误的向上转型方式:编译器没有加上内存偏移,pb仍然指向Derived类型的起始地址,即Derived::x
//     void * pv=pd;
//     Base2 *pb= static_cast<Base2*>(pv);
//     cout<<pd->y<<"         "<<pb->y<<endl;
                                                                                                        

//     // 正确向上转型:编译器加上内存偏移，pb指向Base2类型的起始地址,即Base2::y
//     // Base2 *pb= static_cast<Base2*>(pd);
//     // cout<<pd->y<<"         "<<pb->y<<endl;

//     // delete pb;
//     return 0;
// }



const float PI = 3.14;
class Shape
{
public:
    virtual ~Shape()=0;
};
Shape::~Shape(){

}


class Circle:public Shape{
    float r;
public:
    Circle(float a):r(a){}
    virtual ~Circle(){
        
    }
    float GetArea(){
        return r*r*PI;
    }
};
class Rectangle:public Shape{
protected:
    float width;
    float height;
public:
    Rectangle(int a,int b):width(a),height(b){}
    virtual ~Rectangle(){
            
    }
    virtual float GetArea(){
        return height*width;
    }
};
class Square:public Rectangle{
public:
    Square(float a1,float a2):Rectangle(a1,a2){}
    virtual ~Square(){
            
    }
    virtual float GetArea(){
        return height*width;
    }
};

int main(){
    Circle c(1);
    cout<<c.GetArea()<<endl;
    Rectangle r(1,3);
    cout<<r.GetArea()<<endl;
    Square s(1,1);
    cout<<s.GetArea()<<endl;

    shared_ptr<Rectangle> pr(new Square(3,3));
    cout<<pr->GetArea()<<endl;

    return 0;
}


