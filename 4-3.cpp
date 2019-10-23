#include<iostream>
using namespace std;
const float PI=3.14159;
const float FENCE_PRICE=35;
const float CONCRET_PRICE=20;
class Circle{
public:
    Circle(float r);
    float circumference();
    float area();
private:
    float radius;
};
int main(){
    float radius;
    cout<<"Enter the radius of the circle!"<<endl;
    cin>>radius;
    Circle pool(radius);
    Circle poolRim(radius+3);
    float fenceCost = poolRim.circumference()*FENCE_PRICE;
    cout<<"Fencing Cost is "<<fenceCost<<endl;
    float concreteCost=(poolRim.area()-pool.area())*CONCRET_PRICE;
    return 0;
}
Circle::Circle(float r){
    radius=r;
}
float Circle::circumference(){
    return 2*PI*radius;
}

float Circle::area(){
    return PI*radius*radius;
}
