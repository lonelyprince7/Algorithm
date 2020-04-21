#include<bits/stdc++.h>
using namespace std;
struct Point{
    double x;
    double y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
};
const double eps = 1e-6;
 
const double Pi = acos(-1.0);
 
struct Seg
{
    Point p1,p2;
};
 
int sgn(double x)
{
    return x<-eps ? -1 : (x>eps);
}
 
double Cross(const Point& p1,const Point& p2,const Point& p3,const Point& p4)
{
    return (p2.x-p1.x)*(p4.y-p3.y) - (p2.y-p1.y)*(p4.x-p3.x);
}
 
double Area(const Point& p1,const Point& p2,const Point& p3)
{
    return Cross(p1,p2,p1,p3);
}
 
double fArea(const Point& p1,const Point& p2,const Point& p3)
{
    return fabs(Area(p1,p2,p3));
}
 
bool Meet(const Point& p1,const Point& p2,const Point& p3,const Point& p4)
{
    return max(min(p1.x,p2.x),min(p3.x,p4.x)) <= min(max(p1.x,p2.x),max(p3.x,p4.x))
        && max(min(p1.y,p2.y),min(p3.y,p4.y)) <= min(max(p1.y,p2.y),max(p3.y,p4.y))
        && sgn(Cross(p3,p2,p3,p4) * Cross(p3,p4,p3,p1)) >= 0
        && sgn(Cross(p1,p4,p1,p2) * Cross(p1,p2,p1,p3)) >= 0;
}
 
Point Inter(const Point& p1,const Point& p2,const Point& p3,const Point& p4)
{

    double k = fArea(p1,p2,p3) / fArea(p1,p2,p4);
    return Point((p3.x + k*p4.x)/(1+k),(p3.y + k*p4.y)/(1+k));
}

// 代码方面，我并没有按照书上的写法来写，而是直接求出“比”k，然后利用通分前的公式计算。
// 书上那样写可能是因为前面已经求得了两个叉积，直接使用更方便的关系。

// 下面是书中的写法。

// Point Inter(const Point& p1,const Point& p2,const Point& p3,const Point& p4)
// {
//     double s1 = fArea(p1,p2,p3) , s2 = fArea(p1,p2,p4);
//     return Point((p4.x*s1+p3.x*s2)/(s1+s2),(p4.y*s1+p3.y*s2)/(s1+s2));
// }


int main(){
    vector<int> start1={0,0};
    vector<int> end1={1,1};
    vector<int> start2={1,0};
    vector<int> end2={2,1};
    Point p1(start1[0],start1[1]);
    Point p2(end1[0],end1[1]);
    Point p3(start2[0],start2[1]);
    Point p4(end2[0],end2[1]);
    if(
        Meet(p1,p2,p3,p4) 
    )
    {
        Point res=Inter(p1,p2,p3,p4);
        cout<<res.x<<" "<<res.y<<endl;
    }
    else cout<<"no"<<endl;
    return 0;
}