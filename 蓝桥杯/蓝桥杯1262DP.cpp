#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;
int n,a,b;
long long res=-999999999999;
long long dp[100005]; //以某个节点为根的最小值
long long  vertex[100005];//记录每个节点的权值
bool book[100005]; //标记节点是否访问过
vector<list<int>> edges(100005); //每个节点的邻接表
void dfs(int cur){
    dp[cur]=vertex[cur];
    book[cur]=1;
    for(auto i:edges[cur]){
        if(!book[i]){
            dfs(i);
            if(dp[i]>0) dp[cur]+=dp[i];
        }
    }
    res=max(res,dp[cur]);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>vertex[i];
    }
    for(int i=1;i<=n-1;++i){
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1);//任意一个节点开始搜索均可，反正最后也要记录以每个节点为根的最优值,\
    注意等效对称性,不管以哪个节点开始，最后结果都会是都是一个以某节点为根的大树和若干个某节点的子树
    cout<<res<<endl;
    return 0;
}