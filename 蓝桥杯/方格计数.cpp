//本题考察由题目得到算法递推式
#include<bits/stdc++.h>
using namespace std;
double Y[50001];
int cnt[50001];
int main(){
    long long res=0;
    for(int x=0;x<=50000;++x){
       Y[x]=sqrt(pow(50000,2)-pow(x,2));
    }
    for(int x=0;x<=50000;++x){
        cnt[x]=(int)(Y[x]);
    }
    for(int x=0;x<=49999;++x){
        if(cnt[x+1]==cnt[x]) res+=cnt[x];
        else res+=cnt[x+1];
    }
    cout<<res*4<<endl;
    return 0;
}