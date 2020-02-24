#include<iostream>
using namespace std;
int n,p[30000],f[30000],cnt;
void shai(int x){
    for(int i=2;i<=n;i++){
        if(f[i]==0)p[++cnt]=i; //先把2加入
        for(int j=1;j<=cnt&&i*p[j]<=n;j++){ //遍历小于这个数的质数（直到质因数）,把质数和此数的乘积筛掉
            f[i*p[j]]=1;
            if(i%p[j]==0)break; //遍历了最小质因数后跳出循环
        }
    }
}
int main(){
    cin>>n;
    shai(n);
    for(int i=1;i<=cnt;i++)cout<<p[i]<<' ';
}