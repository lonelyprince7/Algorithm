/*
 * @Descripttion: 
 * @Version: 1.0
 * @Author: ZhangHongYu
 * @Date: 2020-11-03 21:25:43
 * @LastEditors: ZhangHongYu
 * @LastEditTime: 2020-11-12 15:59:15
 */
# define index(x,y,dy) ((x)*(dy)+(y))
#include<iostream>
using namespace std;
long long dp[10000005];
int t[10005];
int v[10005];
int main(){
    int tot_t,n;
    cin>>tot_t>>n;
    for(int i=1;i<=n;++i){
        cin>>t[i]>>v[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=tot_t;++j){
            if(t[i]>j) dp[index(i,j,tot_t+1)]=dp[index(i-1,j,tot_t+1)];
            else dp[index(i,j,tot_t+1)]=max(dp[index(i-1,j,tot_t+1)],dp[index(i,j-t[i],tot_t+1)]+v[i]);
        }
    }
    cout<<dp[index(n,tot_t,tot_t+1)]<<endl;
    return 0;
}