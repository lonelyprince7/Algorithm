#include<bits/stdc++.h>
using namespace std;
//本题用素数筛法解决
typedef long long ll;
map<long long,bool> m;
int e[3]={3,5,7};
void dfs(ll t){
    if(t>59084709587505) return;
    for(int i=0;i<3;++i){
        t*=e[i];
        dfs(t*dfs[i]);
        t/=e[i];
    }
    
}
int main(){
    ll t=1;
    dfs(t);
    return 0;
}