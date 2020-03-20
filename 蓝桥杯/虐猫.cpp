//本题使用分治算法
#include<bits/stdc++.h>
using namespace std;
struct point{
    int x;
    int y;
    int dis;
    point(int a,int b):x(a),y(b){}
};
queue<point> q;
int nums[10005][10005];
int book[10005][10005];
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            cin>>nums[i][j];
        }
    }
    int s1,s2,t1,t2;
    cin>>s1>>s2>>t1>>t2;
    book[s1][s2]=1;
    q.push(point(s1,s2));
    int res=0;
    while(!q.empty()){
        point p=q.front();
        q.pop();
        if(p.x==t1&&p.y==t2){
            res=book[p.x][p.y];
            break;
        }
        for(int i=0;i<4;++i){
            int row=p.x+mv[i][0];
            int col=p.y+mv[i][1];
            if(row>=1&&row<=m&&col>=1&&col<=n&&!book[row][col]){
                book[row][col]=book[p.x][p.y]+1;
                q.push(point(row,col));
            }
        }
    }
    cout<<res<<endl;
    return 0;
}