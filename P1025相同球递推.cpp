#include<iostream>
using namespace std;    //相同的球划分进相同的盒子
int f[201][7];
int main(){
    int n,k;
    cin>>n>>k;
    f[0][0]=1;        //i<x,f[i][x]=0 i=x,f[i][x]=1
    f[0][1]=0;
    f[1][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=min(i,k);++j){
            f[i][j]=f[i-1][j-1]+f[i-j][j];  //注i-j是重点　至少有一个盒子只有一个小球,等价于f[i-1][j-1],没有一个盒子只有一个小球->每个盒子都拿出一个小球，等价于f[i-j][j]
        }
    }
    std::cout<<f[n][k]<<endl;
    return 0;
}