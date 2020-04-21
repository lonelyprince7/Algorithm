#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums{2,1,2,6,1,8,10,10};
    int dp[nums.size()][3];
    if(nums.size()==0){
        cout<<"0"<<endl;
        return 0;
    }
    dp[0][0]=0;
    dp[0][1]=nums[0];
    dp[0][2]=1; //标记是否选了第一个数
    int res=nums[0];
    for(int i=1;i<nums.size();++i){
        int max_index=i;
        int max_val=0;
        dp[i][2]=0;
        for(int j=i-2;j>=0;--j){
            if(dp[j][1]>max_val){
                if(i==nums.size()-1&&dp[j][2]==1){ //最后一个数特判
                    if(dp[j][1]-nums[0]>max_val){
                        max_val=dp[j][1]-nums[0];
                        max_index=j;
                    }
                    continue;
                }
                max_val=dp[j][1];
                max_index=j;
            }
        }
        dp[i][2]=dp[max_index][2]; //传递标记
        dp[i][0]=max_index;
        dp[i][1]=nums[i]+max_val;
        res=max(res,dp[i][1]);
    }
    cout<<res<<endl;
    return 0;
}