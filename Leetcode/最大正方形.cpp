#include<bits/stdc++.h> //此题为dp,O(MN),仿照lcs
using namespace std;
int main(){
    vector<vector<char>> matrix={
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0},
    };
    int res=-1;
    vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
    for(int i=0;i<dp.size();++i){
        for(int j=0;j<dp[i].size();++j){
            if(i==0||j==0){
                if(matrix[i][j]=='0') dp[i][j]=0;
                else dp[i][j]=1;
            }
            else{
                int cnt=0;
                for(int off=0;off<=dp[i-1][j-1];++off){
                    if(matrix[i][j-off]=='0'||matrix[i-off][j]=='0') break;
                    cnt++;
                }
                dp[i][j]=cnt;
            }
            res=max(res,dp[i][j]);
        }
    }
    cout<<pow(res,2)<<endl;
    return 0;
}