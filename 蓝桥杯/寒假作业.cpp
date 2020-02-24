//本题在DFS的基础上进行巧妙的剪枝优化算法时间复杂度
#include<bits/stdc++.h>
using namespace std;
float book[12],w[12],res;
void dfs(int cur){
    if(cur==12) return; 
    //剪枝
    if(cur==3&&w[0]+w[1]!=w[2]) return;
    if(cur==6&&w[3]-w[4]!=w[5]) return;
    if(cur==9&&w[6]*w[7]!=w[8]) return;
    for(int i=1;i<=13;++i){
        if(!book[i]){
            book[i]=1;w[cur]=i;
            if(cur==11&&w[9]/w[10]==w[11]){
                res++;
            }
            dfs(cur+1);
            book[i]=0;w[cur]=-999;
        }
    }
}
int main(){
    dfs(0);
    cout<<res<<endl;
    return 0;
}