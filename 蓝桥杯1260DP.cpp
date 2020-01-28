#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>
using namespace std;
int res,n,a,b,val;
int dp[100005];
int vertex[100005];
bool book[100005];
vector<pair<int,int>> edges(100005);
int DP(int cur){
    int res=vertex[cur];
    book[cur]=1;
    for(int i=1;i<=n-1;++i){
        if(edges[i].first==cur&&!book[edges[i].second]){
            int t=DP(edges[i].second);
            if(t>0) res+=t;
        }
        else if(edges[i].second==cur&&!book[edges[i].first]){
            int t=DP(edges[i].first);
            if(t>0) res+=t;
        }
    }
    return res;
}
int main(){
    cin>>n;
    int cnt=1;
    for(int i=1;i<=n;++i){
        cin>>vertex[i];
    }
    for(int i=1;i<=n-1;++i){
        cin>>a>>b;
        edges[cnt++]=make_pair(a,b);
    }
    int res=-999999;
    for(int i=1;i<=n;++i){
        //选择根节点
        memset(book,0,sizeof(bool)*100005);
        res=max(res,DP(i));
    }
    cout<<res<<endl;
    return 0;
}