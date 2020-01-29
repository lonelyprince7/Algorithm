#include<iostream>
using namespace std;
int f[100005];
int main(){
    int K,N;
    cin>>N>>K;
    f[0]=1;
    for(int i=1;i<=N;++i){
        f[i]=0;
        for(int j=1;j<=min(i,K);++j){
            f[i] +=f[i-j];
            if(f[i]>100003) f[i]%=100003; //加法也符合取模运算律
        }
    }
    cout<<f[N]%1000003<<endl;
    return 0;
}