//本题在暴力的基础上通过剪枝手段优化算法的时间复杂度
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int t;
    while(cin>>n){
        int t2,t3,t4,tmp;
        int i,j,k,l;
        for(i=0;i<=sqrt(n);++i){
            t2=n-i*i;
            for(j=i;j<=sqrt(t2);++j){
                t3=t2-j*j;
                for(k=j;k<=sqrt(t3);++k){
                    t4=t3-k*k;
                    tmp=sqrt(t4); //这里巧妙脱一层循环，因为答案最后一个数必须被整开方
                    if(tmp*tmp==t4) goto point;
                }
            }
        }
        point: cout<<i<<" "<<j<<" "<<k<<" "<<tmp<<" "<<endl;
    }
    return 0;
}