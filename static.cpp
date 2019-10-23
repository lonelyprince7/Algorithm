#include<iostream>
#include<cmath>
using namespace std;
class Point{
public:
    Point(int a=0,int b=0):x(a),y(b){count++;}
    static int GetCount(){
        return count;
    }
    friend double distance(const Point& a,const Point& b);
    double distance(const Point& other);
    int Getx()const{
        return x;
    }
    int Gety()const{
        return y;
    }
private:
    static int count;
    int x;
    int y;  
};
double distance(const Point& a,const Point& b){
    return sqrt(pow((a.x-b.x),2)+pow((b.y-a.y),2));
}
double Point::distance(const Point& other){
    int x2=other.Getx();
    int y2=other.Gety();
    return sqrt(pow((x-x2),2)+pow((y-y2),2));
}


int Point::count=0;
int main(){
    Point P1(2,3);
    Point P2(3,2);
    cout<<Point::GetCount()<<endl;
    cout<<P1.distance(P2)<<endl;
}