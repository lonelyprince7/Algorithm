#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dp[n+1];
    for(int i=1;i<=n;i++){
        dp[i]=1;  
        for(int j=i/2;j>=1;j--){
            dp[i] += dp[j];
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}