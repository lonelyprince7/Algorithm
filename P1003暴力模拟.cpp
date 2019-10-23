#include<iostream>
#include<vector>
#include<map>
#include<tuple>
using namespace std;
// class point{
//  public:
//     int _x;
//     int _y;
//     point(int x,int y):_x(x),_y(y){}
//     point(const point& p){
//         _x=p._x;
//         _y=p._y;
//     }
//     point operator=(const point& p){
//         _x=p._x;
//         _y=p._y;
//     }
//     bool operator<(const point& p){
//         if(_x==p._x) return p._y<p._y;
//         else return _x<p._x;
//     }
//     bool operator==(const point& p){
//         return _x<p._x&&_y<p._y;
//     }

// };
// std::map<point,std::string> multiMap;
int range[10005][4];
int main(){
    // int n,a,b,g,k,x,y;
    // std::cin>>n;
    // for(int u=1;u<=n;++u){
    //     std::cin>>a>>b>>g>>k;
    //     for(int v=a;v<=a+g;++v)
    //         for(int w=b;w<=b+k;++w)
    //         point p(v,w);
    //         multiMap[p]=std::to_string(u);
    // }
    // std::cin>>x>>y;
    // point p(x,y);
    // for(auto iter=multiMap.begin();iter!=multiMap.end();++iter){
    //     if(p==iter->first){
    //         std::cout<<iter->second;
    //         return 0;
    //     }
    // }
    // std::cout<<"-1";
    int n,a,b,x,y;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>range[i][0]>>range[i][1]>>range[i][2]>>range[i][3];
        range[i][2]+=range[i][0];
        range[i][3]+=range[i][1];
    }
    cin>>a>>b;
    for(int i=n;i>=1;--i){
         if(a>=range[i][0]&&b>=range[i][1]&&a<=range[i][2]&&b<=range[i][3]){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}  
