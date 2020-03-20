#include<bits/stdc++.h> //本题为dp,类似lcs的模板题,也可看出组合数学格路径问题
using namespace std;
int main(){
    int m,n;
    //res=0;
    cin>>m>>n;
    //int res=-1;
    int dp[m][n];
    memset(dp,0,sizeof(int)*m*n);
    dp[m-1][n-1]=1;
   // dp[m-1][n-1]=0;
    //res=max(res,dp[m-1][n-1]);
    for(int i=m-1;i>=0;--i){
        for(int j=n-1;j>=0;--j){
            if(i<m-1){
                dp[i][j]+=dp[i+1][j];
            }
            if(j<n-1){
                dp[i][j]+=dp[i][j+1];
            }
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}