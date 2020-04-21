#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums={1};
    vector<int> dp(nums.size(),0);
    if(nums.size()==0) return 0;
    int res=nums[0];
    for(int i=0;i<dp.size();++i){
        dp[i]=nums[i];
        for(int j=0;j<=i-2;++j){
            dp[i]=max(dp[i],dp[j]+nums[i]);
        }
        res=max(res,dp[i]);
    }
    cout<<res<<endl;
    return 0;
}