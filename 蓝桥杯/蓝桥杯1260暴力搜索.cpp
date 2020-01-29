#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
int sum(int a,int b,int c,int d){
    int res=0;
    for(int i=1;i<=49;++i){
        if(i==a||i==b||i==c||i==d) continue;
        res+=i;
    }
    return res;
}
int main(){

    for(int i=1;i<=46;++i){
        for(int j=i+2;j<=48;++j){
            if((i*(i+1)+j*(j+1)+sum(i,i+1,j,j+1))==2015)
            cout<<i<<endl;
        }
    }
    return 0;
}