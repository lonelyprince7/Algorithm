#include<iostream>
using namespace std;
class Point{
    int x;
    int y;
public:
    Point(int a,int b){
        x=a;
        y=b;
    }
    Point(const Point& other){
        x=other.x;
        y=other.y;
    }
    void SetX(int a){
        x=a;
    }
    void SetY(int b){
        y=b;
    }
};
int main(){
    Point a(1,2); 
    Point b(a);
    a.SetX(11);
    Point c=a;
    
    return 0;
}