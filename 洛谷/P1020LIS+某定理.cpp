#include<iostream> 
#include<algorithm>
#define size 100000
using namespace std;
int a[size];
int dp[size];
int main(){
    int cnt=0;
    int t;
    while(cin>>t){
        a[cnt++]=t;
    }
    int res1=1;
    for(int i=0;i<cnt;++i){
        int n_max=1;
        for(int j=0;j<i;++j){
            if(a[j]>=a[i]){
                n_max=max(n_max,dp[j]+1);
            }
        }
        dp[i]=n_max;
        res1=max(res1,dp[i]);
    }
    
    int res2=1;
    for(int i=0;i<cnt;++i){
        int n_max=1;
        for(int j=0;j<i;++j){
            if(a[j]<=a[i]){
                n_max=max(n_max,dp[j]+1);
            }
        }
        dp[i]=n_max;
        res2=max(res2,dp[i]);
    }
    cout<<res1<<endl<<res2<<endl;
    return 0;
}
