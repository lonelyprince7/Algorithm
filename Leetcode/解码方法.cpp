//本题采用动态规划求解.注意本题dp下标比s下标多1,还有，此题边界条件处理异常恶心比如什么22330,10这种
#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int main(){
    string s;
    while(cin>>s){
        dp[0]=1;
        if(s[0]=='0'){
            cout<<0<<endl;
            continue;
        }
        dp[1]=1;
        for(int i=1;i<=s.length();++i){
            int t=(s[i-1]-'0')*10+s[i]-'0';
            //状态转移时两种情况可供选择，是自成一个，还是和前面结合多加一个
            if(s[i]=='0'&&s[i-1]!='0'&&t>=1&&t<=26){
                dp[i+1]=dp[i-1];
            }
            else if(s[i]!='0'&&s[i-1]!='0'){
                if(t<=26&&t>=1) dp[i+1]=dp[i-1]+dp[i];
                else dp[i+1]=dp[i];
            }
            else if(s[i]!='0'&&s[i-1]=='0'){
                dp[i+1]=dp[i];
            }
            else {
                cout<<"0"<<endl;return 0;
            }
        }
        cout<<dp[s.length()]<<endl;
    }
    return 0;
}