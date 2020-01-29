/*
给定n个盒子，第i个盒子有ai朵花，现在从中选取m朵花，问选取方案数
用容斥定理解决 m=x1+x2+..+xn
C(m+n-1,n-1)+sum{ (-1)^p * C(m+n-1-(1+n1)-(1+np),n-1) } 
    
*/
//这道题等价为13个盒子，每个盒子4个球，取13个球的取法个数
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
ll ans,n,s,A[30],inv[30];

ll Pow(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2)
            res=res*a%mod;
        b>>=1;a=a*a%mod;
    }
    return res;
}
ll C(ll y,ll x){
    if(y<0||x<0||y<x)return 0;
    y%=mod;
    if(y==0|| x==0)return 1;
    ll ans=1;
    for(ll i=0;i<x;i++)
        ans=(ll)ans*(y-i)%mod;
    for(ll i=1;i<=x;i++)
        ans=ans*inv[i]%mod;
    return ans;
}

int main(){
    cin>>n>>s;
    for(ll i=1;i<=20;i++)
        inv[i]=Pow(i,mod-2);
    
    for(int i=0;i<n;i++)cin>>A[i];
    
    for(ll i=0;i<(1<<n);i++){
        ll a=n-1,b=s+n-1,tmp=0;
        if(i==0){
            ans=(ans+C(b,a))%mod;
            continue;
        }
        for(int j=0;j<n;j++)
            if(i & ((ll)1<<j)){
                tmp++;
                b-=A[j]+1;
            }
        if(tmp%2){//减法 
            ans=(ans-C(b,a))%mod;
            ans=(ans+mod)%mod;
        }
        else {
            ans=(ans+C(b,a))%mod;
        } 
    }
    cout<<ans<<'\n';
}