/*
 * @Descripttion: 
 * @Version: 1.0
 * @Author: ZhangHongYu
 * @Date: 2020-11-03 21:25:43
 * @LastEditors: ZhangHongYu
 * @LastEditTime: 2020-11-03 22:37:15
 */
#include<iostream>
using namespace std;
int dp[105][1005];
int t[105];
int v[105];
int main(){
    int tot_t,n;
    cin>>tot_t>>n;
    for(int i=1;i<=n;++i){
        cin>>t[i]>>v[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=tot_t;++j){
            if(t[i]>j) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-t[i]]+v[i]);
        }
    }
    cout<<dp[n][tot_t]<<endl;
    return 0;
}