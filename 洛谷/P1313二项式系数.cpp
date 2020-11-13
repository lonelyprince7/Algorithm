#include<iostream>
using namespace std;
int f[1005][1005];
int pow(int n,int k){
    long long res=1;
    long long base=n;
    while(k){
        if(k&1){
            res *=base;
            res %=10007;
        }  
        base *= base;
        base %=10007;
        k >>=1;
    }
    return res;
}
int comb(int n,int m){
    if(n==m||m==0||n==0) return 1;
    f[1][0]=f[1][1]=1;
    for(int i=2;i<=n;++i){
        f[i][0]=f[i][i]=1;
        for(int j=1;j<=i-1;++j){
            f[i][j]=(f[i-1][j]+f[i-1][j-1])%10007;
        }
    }
    return f[n][m];
}
int main(){
    int a,b,k,n,m;
    cin>>a>>b>>k>>n>>m;
    int res1=comb(k,n)*pow(a,n)%10007;
    int res=res1*pow(b,m)%10007;
    cout<<res<<endl;
    return 0;
}