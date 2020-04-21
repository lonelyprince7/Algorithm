#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct p{
    int x;
    int y;
    p(int a,int b):x(a),y(b){}
};
int sum(int a,int b){
    int c1=0;int c2=0;
    while(a){
        c1+=a%10;
        a/=10;
    }
    while(b){
        c2+=b%10;
        b/=10;
    }
    return c1+c2;
}
int book[1005][1005];
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int res,m,n,k;
int main(){
    m=16;n=8;k=4;
    queue<p> q;
    q.push(p(0,0));
    res++;book[0][0]=1;
    while(!q.empty()){
        p f=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            int rrow=f.x+mv[i][0];
            int ccol=f.y+mv[i][1];
            if(rrow>=0&&rrow<m&&ccol>=0&&ccol<n&&!book[rrow][ccol]&&sum(rrow,ccol)<=k){
                res++;book[rrow][ccol]=1;
                q.push(p(rrow,ccol));
            }
        }
    }
    cout<<res<<endl;
}