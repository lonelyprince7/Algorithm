#include<iostream>
using namespace std;
int func(int n){
    int res=0;
    int temp;
    while(n>=3){
        temp=n%3;
        res+=(n-temp);
        n=(n/3)+temp;
    }
    res+=n;
    return res;
}
int main(){
    int n,res;
    while(cin>>n){
        res=func(n);
        cout<<res<<endl;
    }
    return 0;
}