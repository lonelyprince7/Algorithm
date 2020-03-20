#include<bits/stdc++.h> //此题为简单dp
using namespace std;
int main(){
    vector<int> prices={1,2,7,6,4,3,1};
    if(prices.size()==0) return 0;
    int res=-1;
    int dp[prices.size()];
    dp[0]=prices[0];
    res=max(res,prices[0]-dp[0]);
    for(int i=1;i<prices.size();++i){
        if(prices[i]<dp[i-1]){
            dp[i]=prices[i];
        }
        else{
            dp[i]=dp[i-1];
        }
        res=max(res,prices[i]-dp[i]);
    }
    cout<<res<<endl;
    return 0;
}