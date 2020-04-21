#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> prices{1};
    int dp[prices.size()];
    int res=1;
    for(int i=0;i<prices.size();++i){
        dp[i]=1;
        for(int j=i-1;j>=0;--j){
            if(prices[j]<prices[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res=max(res,dp[i]);
    }
    cout<<res<<endl;
    return 0;
}