/*
 * @Descripttion: 
 * @Version: 1.0
 * @Author: ZhangHongYu
 * @Date: 2020-11-03 21:25:43
 * @LastEditors: ZhangHongYu
 * @LastEditTime: 2020-11-12 15:16:22
 */
#include<iostream>
#include<cmath>
using namespace std;
long long dp[25][25];
int n,m,a,b;
int main(){
    cin>>n>>m>>a>>b;
    for(int i=1;i<=n+1;++i){
        for(int j=1;j<=m+1;++j){
            if((abs(i-1-a)==2&&abs(j-1-b)==1)||(abs(i-1-a)==1&&abs(j-1-b)==2)||((i-1)==a&&(j-1)==b)){
                dp[i][j]=0;
            }
            else{
                if(i==1&&j==1) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout<<dp[n+1][m+1]<<endl;
    return 0;
}