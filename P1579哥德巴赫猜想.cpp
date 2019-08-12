#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
bool isprime(int n){
    int p[8]={4,2,4,2,4,6,2,6};
    int i=7,j,q;
    if(n==1)return 0;
    if(n==2||n==5||n==3)return 1;
    if(n%2==0||n%3==0||n%5==0)return 0;
    q=(int)sqrt(n);
    for(;i<=q;){
        for(j=0;j<8;j++){
            if(n%i==0)return 0;
            i+=p[j];
        }
        if(n%i==0)return 0;
    }
    return 1;
}
int res[4],tmp[4];
void dfs(int n,int count){
    if(count==2&&isprime(n)){
        tmp[++count]=n;
        if(tmp[1]<res[1]){
            res[1]=tmp[1];
            res[2]=tmp[2];
            res[3]=tmp[3];
        }
        else if(tmp[1]==res[1]){
            if(tmp[2]<res[2]){
                res[1]=tmp[1];
                res[2]=tmp[2];
                res[3]=tmp[3];
            }
        }
        return;
    }
    else if(count==2) return;
    for(int i=2;i<n;++i){
        if(isprime(i)){
            tmp[++count]=i;
            dfs(n-i,count);
            count--;
        }
    }
}
int main(){
    memset(res,20001,sizeof(int)*4);
    memset(tmp,20002,sizeof(int)*4);
    int n;
    cin>>n;
    dfs(n,0);
    cout<<res[1]<<" "<<res[2]<<" "<<res[3];
    return 0;
}