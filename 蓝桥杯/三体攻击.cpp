#include<bits/stdc++.h>
using namespace std;
int d[1000005];
int index(int i,int j,int k,int b,int c){
    return ((i-1)*b+(j-1))*c+(k-1)+1;
}
int main(){//本题考查矩阵的行优先存放形式
    int a,b,c,m,cnt=0;
    cin>>a>>b>>c>>m;
    for(int p=1;p<=a*b*c;++p){
        cin>>d[p];
    }
    int lat,rat,lbt,rbt,lct,rct,ht;
    for(int i=1;i<=m;++i){
        cin>>lat>>rat>>lbt>>rbt>>lct>>rct>>ht;
        for(int p=lat;p<=rat;++p){
            for(int q=lbt;q<=rbt;++q){
                for(int r=lct;r<=rct;++r){
                    d[index(p,q,r,b,c)]-=ht;
                    if(d[index(p,q,r,b,c)]<0){
                        cout<<i<<endl;
                        return 0;
                    }
                }
            }
        }

    }
    return 0;
}