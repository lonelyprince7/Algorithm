/*
 * @Descripttion: 
 * @Version: 1.0
 * @Author: ZhangHongYu
 * @Date: 2020-11-09 15:16:46
 * @LastEditors: ZhangHongYu
 * @LastEditTime: 2020-11-09 21:58:51
 */
#include<iostream>
#include<algorithm>
using namespace std;
int dp[2005][2005];
int main(){
    string a,b;
    cin>>a>>b;
    for(int j=1;j<=b.length();++j) dp[0][j]=j;
    for(int i=1;i<=a.length();++i) dp[i][0]=i;
    for(int i=1;i<=a.length();++i){
        for(int j=1;j<=b.length();++j){
            if(a[i-1]==b[j-1]){ //字符串从0开始要-1
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(min(dp[i-1][j-1]+1,dp[i][j-1]+1),dp[i-1][j]+1);
            }
        }
    }
    cout<<dp[a.length()][b.length()]<<endl;
    return 0;
}