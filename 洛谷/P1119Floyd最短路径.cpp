#include<iostream>
#include<algorithm>
using namespace std;
struct vertex{
    int t;
    int num;
    vertex() {}
    vertex(int a,int b):num(a),t(b){}
};
vertex n[205];
int m[205][205];
int N,M;
inline void update(int k){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
           m[i][j]=m[j][i]=min(m[i][j],m[i][k]+m[k][j]);
        }
    }
}
int main(){
    int t,u,v,w,q,cur;
    cin>>N>>M;
    for(int i=0;i<N;++i){
        cin>>t;
        vertex a(i,t);
        n[i]=a;
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(i==j) m[i][j]=m[j][i]=0;
            else m[i][j]=m[j][i]=1e6;
        }
     }
    for(int i=0;i<M;++i){
        cin>>u>>v>>w;
        m[u][v]=m[v][u]=w;         //两点之间无中转的直接路径长度
    }
    cin>>q;
    cur=0;
    for(int i=0;i<q;++i){
        cin>>u>>v>>t;
        while(cur<N&&t>=n[cur].t){  //cur<N
            update(cur);  //更新两点之间可能有中转的路径长度
            cur++;
        }
        if(n[u].t>t||n[v].t>t) cout<<"-1"<<endl;    //次情况容易漏掉，村庄没有建好
        else if(m[u][v]==1e6) cout<<"-1"<<endl;  //村庄之间没有路
        else cout<<m[u][v]<<endl;
    }
    return 0;
}

