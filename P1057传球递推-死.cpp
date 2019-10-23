#include<iostream>
using namespace std;
int f[35][35];
int main(){
    int m,n;
    cin>>m>>n; //注意:同学编号从０开始方便取余数
    f[1][0]=0; //不可能１轮不动
    f[1][1]=1;
    f[1][n-1]=1;   //至少两个人来算滴，这里两个人是基准情形  而且８　９行的两种情况对应顺时针逆时针
    for(int i=2;i<=m;++i) //第几轮，从１开始
    {
        for(int j=0;j<n;++j) //传到第几号的可能性总数，编号从０开始
        {
            f[i][j]=f[i-1][(j-1+n)%n]+f[i-1][(j+1)%n];   //逆时针顺时针不重复要单算
        }
    }
    cout<<f[m][0]<<endl;
    return 0;
}