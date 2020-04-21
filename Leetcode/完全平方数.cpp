#include<bits/stdc++.h>
#define inf 9999
using namespace std;
int main(){
    int n=13;
    int dp[n+1];
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+1;
        for(int j=1;j*j<=i;j++){
            dp[i]=min(dp[i],dp[i-j*j]+1);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}