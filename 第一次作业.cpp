// #include<iostream>
// using namespace std;
// int getPower(int x,int y){
//     int base=x;
//     int res=1;
//     while(y){
//         if(y&1){
//             res*=base;
//         }
//         base *=base;
//         y >>=1;
//     }
//     return res;
// }
// int main(){
//     int x,y,z;
//     cin>>x>>y;
//     z=getPower(x,y);
//     cout<<z<<endl;
//     return 0;
// }
#include <iostream>
#include <cstdlib>

using namespace std;

double fun(int n,int x);

int main(){
    int n;
    double x;
    cout<<"输入勒让德多项式的n和x:";
    cin>>n>>x;
    double fin=fun(n,x);
    cout<<"结果是："<<fin<<endl;
    
    return 0;
}

double fun(int n,int x){
    if(n==0)
        return 1;
    else if (n==1)
        return  x;
    else if(n>1)
        return ((2*n-1)*x-fun(n-1,x)-(n-1)*fun(n-2,x))/n;
    else{
        cout<<"非法输入！！"<<endl;
        return 0;
    }
}

