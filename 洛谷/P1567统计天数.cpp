#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int dp[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    if(n==1){
        cout<<"1"<<endl;
        return 0;
    }
    dp[0]=1;
    for(int i=1;i<n;++i){
        dp[i]=a[i]>a[i-1]?1+dp[i-1]:1;
    }
    int max=dp[0];
    for(int i=1;i<n;++i){
        if(dp[i]>max){
            max=dp[i];
        }
    }
    cout<<max<<endl;
    return 0;
}