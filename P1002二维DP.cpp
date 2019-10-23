#include<iostream>
using namespace std;
long long dp[1000][1000];bool map[1000][1000];
void horse(int hx,int hy){
    map[hx][hy]=1;
    map[hx-2][hy+1]=1;
    map[hx+2][hy+1]=1;
    map[hx-2][hy-1]=1;
    map[hx+2][hy-1]=1;
    map[hx-1][hy+2]=1;
    map[hx+1][hy+2]=1;
    map[hx-1][hy-2]=1;
    map[hx+1][hy-2]=1;
    return ;
}
int main(){
    int n,m,hx,hy;
    cin>>n>>m>>hx>>hy;
    horse(hx,hy);
    dp[0][0]=1;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(map[i][j]==0){
                if(i==0&&j==0)
                    continue;
                else if(i==0&&j!=0)
                    dp[i][j]=dp[i][j-1];
                else if(i!=0&&j==0)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}