//本题考察由题目得到算法递推式
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//递推式为a=a*a-b*b
//b=2*ab
int main(){
    ll a=2;
    ll b=3;
    for(int i=1;i<=4;++i){
        ll ta=a;
        ll tb=b;
        a=ta*ta-tb*tb;
        b=2*ta*tb;
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}