#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=10;
    int dp[n+1];
    if(n==1) return 0; 
    dp[0]=1;
    dp[1]=1;
    int res=1;
    for(int i=2;i<=n;++i){
        if(n!=i){
            dp[i]=i;
            for(int j=0;j<=i;++j){
                dp[i]=max(dp[i],dp[i-j]*j);
            }
        }
        else{
            dp[i]=i-1;
            for(int j=1;j<=i-1;++j){
                dp[i]=max(dp[i],dp[i-j]*j);
            }
        }
        res=max(dp[i],res);
    }
    cout<<res<<endl;
    return 0;
}