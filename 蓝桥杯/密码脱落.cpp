//本题是经典的LCS问题,采用DP解决
#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
int dp[1005][1005];
int res=0;
int main(){
    string s,r;
    while(std::cin>>s){
        r=s;
        reverse(s.begin(),s.end());
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=s.length();++i){
            for(int j=1;j<=r.length();++j){
                if(s[i]!=r[j]) dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//这里容易错，不是dp[i-1][j-1]           
                else dp[i][j]=dp[i-1][j-1]+1;
            }
        }
        std::cout<<(s.length()-dp[s.length()][r.length()])<<endl;
    }
    return 0;
}