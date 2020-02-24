#include<bits/stdc++.h>
using namespace std;
int nxt[100005];//储存每个小朋友崇拜的人
int pre[100005];//每个小朋友被谁崇拜
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        int t;
        cin>>t;
        nxt[i]=t;
        pre[t]=i;
    }
    int res=0;
    for(int i=1;i<=n;++i){
       if(pre[i]==0) continue;
        int cnt=1;
        int next=nxt[i];
        while(next!=i){
            cnt++;
            next=nxt[next];
        }
       res=max(res,cnt);
    }
    return 0;
}
