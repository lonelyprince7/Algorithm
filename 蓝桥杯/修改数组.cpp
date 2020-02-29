//本题单纯的用map进行标记，然后依次慢慢+1+1...判断的话要超时
//故本题巧妙地运用了并查集，保证少走冤枉路
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int f[1000005];
int Find(int v){
    return f[v]==v?v:Find(f[v]);
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=1000000;++i){
        f[i]=i; //初始化并查集，每个值的根是自己
    }
    for(int i=1;i<=n;++i){
        cin>>a[i];
        int cur=Find(a[i]);
        a[i]=cur;
        f[a[i]]=Find(cur+1);
    }
    for(int i=1;i<=n;++i){
       cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}