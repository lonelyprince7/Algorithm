#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    n=1000000;
    vector<long long> dp;
    dp.resize(n);
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    if(n==2){
        cout<<2<<endl;
    }
    dp[0]=1;
    dp[1]=2;
    dp[2]=4;
    for(int i=3;i<=n-1;++i){
        dp[i]+=dp[i-1]%1000000007;
        dp[i]+=dp[i-2]%1000000007;
        dp[i]+=dp[i-3]%1000000007;
    }
    cout<<dp[n-1]<<endl;
    return 0;
}