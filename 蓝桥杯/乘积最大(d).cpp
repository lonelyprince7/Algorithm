#include<bits/stdc++.h> //本题采用解决单调队列
using namespace std;
typedef long long ll;
ll nums[100005];
ll dp[100005];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    dp[0]=nums[0];
    ll res=dp[0];
    for(int i=1;i<n;++i){
        if(nums[i]==0) dp[i]=0;
        else if(nums[i]>0){
            ll max_val=dp[i-1];
            for(int j=i-1;j>=0;--j){
                max_val=max(max_val,dp[j]);
            }
            if(max_val>=1){
                dp[i]=(nums[i]*max_val)%1000000009;
            }
            else{
                dp[i]=nums[i];
            }
            res=max(res,dp[i]);
        }
        else if(nums[i]<0){
            ll min_val=dp[i-1];
            for(int j=i-1;j>=0;--j){
                min_val=min(min_val,dp[j]);
            }
            if(min_val<=0){
                dp[i]=(nums[i]*min_val)%1000000009;
            }
            else{
                dp[i]=nums[i];
            }
            res=max(res,dp[i]);
        }
    }
    cout<<res<<endl;
    return 0;
}