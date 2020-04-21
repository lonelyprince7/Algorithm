#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> triangle={
     {2},
    {3,4},
   {6,5,7},
  {4,1,8,3}
};
vector<vector<int>> dp=triangle;
int main(){
    if(dp.size()==0)){
        cout<<"0"<<endl;
        return;
    }
    for(int i=triangle.size()-1;i>=0;--i){
        if(i==triangle.size()-1) continue;
        for(int j=triangle[i].size()-1;j>=0;--j){
            dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}