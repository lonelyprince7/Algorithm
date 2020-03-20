#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums={-2,0,-1};
    vector<int> dp(nums.size(),0);
    dp[0]=nums[0];
    int max_val=nums[0];
    for(int i=1;i<nums.size();++i){
        dp[i]=nums[i];
        if(dp[i-1]*nums[i]>dp[i]) dp[i]=dp[i-1]*nums[i];
        max_val=max(max_val,dp[i]);
    }
    cout<<max_val<<endl;
    return 0;
}