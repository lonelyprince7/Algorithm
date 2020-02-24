#include<bits/stdc++.h> //本体用欧拉线性筛
using namespace std;
int n,book[300000],prime[300000],cnt;
int main(){
    cin>>n;
    for(int i=2;i<=n;++i){
        if(book[i]==0) prime[++cnt]=i;
        for(int j=1;j<=cnt;++j){
            if(prime[j]*i>n) break;
            book[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
    for(int i=1;i<=cnt;++i){ //首项
        for(int j=1;j<=2600;++j){ //随便估计一个最大公差2600
            bool flag=1;
            for(int k=1;k<=9;++k){
                if(book[prime[i]+j*k]){
                    flag=0;break;
                }
            }
            if(flag==1){
                cout<<j<<endl;
                return 0;
            }
        }    
    }
   return 0;
}