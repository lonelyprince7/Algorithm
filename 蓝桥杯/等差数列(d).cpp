//本题考查求多个数的最大公因数算法
#include<bits/stdc++.h>
using namespace std;
int n,vgcd,vmin,vmax;
int a[100005];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    cin>>n;
    cin>>a[1];
    vgcd=vmin=vmax=a[1];
    bool flag=1;
    for(int i=2;i<=n;++i){
        cin>>a[i];
        if(a[i]!=a[i-1]) flag=0;
        vgcd=gcd(a[i],vgcd);
        vmin=min(vmin,a[i]);
        vmax=max(vmax,a[i]);
    }
    if(flag==1){
        cout<<n<<endl;return 0;
    }
    cout<<vgcd<<vmin<<vmax<<endl;
    cout<<((vmax-vmin)/vgcd)+1<<endl;
    return 0;
}