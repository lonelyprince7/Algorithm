/*
 * @Descripttion: 
 * @Version: 1.0
 * @Author: ZhangHongYu
 * @Date: 2020-11-03 21:25:43
 * @LastEditors: ZhangHongYu
 * @LastEditTime: 2020-11-08 22:11:45
 */
#include<iostream>
#include<algorithm>
using namespace std;
long long nums[200005];
long long dp[200005];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>nums[i];
    dp[1]=nums[1];
    long long res=nums[1];
    for(int i=1;i<=n;++i){
        dp[i]=max(nums[i],dp[i-1]+nums[i]);
        res=max(res,dp[i]);
    }
    cout<<res<<endl;
    return 0;
}