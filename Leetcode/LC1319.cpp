//DFS+连通性判断
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> connections{{0,1},{0,2},{1,2}};
bool book[100005];
void dfs(int cur){
    book[cur]=1;
    for(int i=0;i<connections.size();++i){
        if(connections[i][0]==cur&&!book[connections[i][1]]){
            dfs(connections[i][1]);
        }
    }
}
int main(){
    int n=4;
    if(connections.size()<n-1){
        cout<<"-1"<<endl;
        return 0;
    }
    int cnt=0;
    for(int i=0;i<n;++i){
        if(!book[i]){
            dfs(i);
            cnt++;
        }
    }
    if(cnt==1) cout<<'0'<<endl;
    else cout<<cnt-1<<endl;
    return 0;
}