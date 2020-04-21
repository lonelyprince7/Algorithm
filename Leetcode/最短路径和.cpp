#include<bits/stdc++.h> //本题为dp,lcs模板题
using namespace std;
int main(){
    vector<vector<int>> grid{
        {1,2,5},
        {3,2,1},
    };
    if(grid.size()==0) return 0;
    int dp[grid.size()][grid[0].size()];
    for(int i=grid.size()-1;i>=0;--i){
        for(int j=grid[0].size()-1;j>=0;--j){
            dp[i][j]=grid[i][j];
            if(i<grid.size()-1&&j<grid[0].size()-1){
                dp[i][j]+=min(dp[i][j+1],dp[i+1][j]);
            }
            else if(j<grid[0].size()-1){
                dp[i][j]+=dp[i][j+1];
            }
            else if(i<grid.size()-1){
                dp[i][j]+=dp[i+1][j];
            }
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}