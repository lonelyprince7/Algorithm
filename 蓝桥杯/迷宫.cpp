//本题迷宫太大,DFS超时,只能使用BFS
#include<bits/stdc++.h> 
#define ROW 30
#define COL 50
using namespace std;
struct point{
    int row;
    int col;
    int level;
    point(int a,int b):row(a),col(b){}
};
char nums[ROW+5][COL+5];
int book[ROW+5][COL+5]; // 
int level[ROW+5][COL+5];//储存每个点的深度
int mv[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
char sign[4]={'D','U','L','R'}; //注意，从后往前和从前往后方向是反的
queue<point> q;
string tmp;
vector<string> strs;;
void dfs(int row,int col){
    if(row==1&&col==1){
        string t=tmp;
        reverse(tmp.begin(),tmp.end());
        strs.push_back(tmp);
        tmp=t;
        return;
    }
    for(int i=0;i<4;++i){
        int rrow=row+mv[i][0];int ccol=col+mv[i][1];
        if(rrow>=1&&rrow<=ROW&&ccol>=1&&ccol<=COL&&\
        !book[rrow][ccol]&&nums[rrow][ccol]=='0'&&\
        level[rrow][ccol]==level[row][col]-1){
            book[rrow][ccol]=1;
            tmp+=sign[i];
            dfs(rrow,ccol);
            book[rrow][ccol]=0;
            tmp.pop_back();
        }
    }
}
int main(){
    ifstream in("/home/lonelyprince7/LocalCode/Algorithm/蓝桥杯/data3.txt");
    string t;
    for(int i=1;i<=ROW;++i){
        getline(in,t);
        for(int j=1;j<=COL;++j){
            nums[i][j]=t[j-1];
        }
    }
    q.push(point(1,1));
    book[1][1]=1;
    level[1][1]=0;
    int height = 0;
    while(!q.empty()){  //先用BFS获得每个点到初始点的距离
        point p=q.front();q.pop();
        int row=p.row;int col=p.col; int cur_level=level[row][col];
        for(int i=0;i<4;++i){
            int rrow=row+mv[i][0];int ccol=col+mv[i][1];
            if(1<=rrow&&rrow<=ROW&&1<=ccol&&ccol<=COL\
            &&!book[rrow][ccol]&&nums[rrow][ccol]=='0'){
                book[rrow][ccol]=1;
                level[rrow][ccol]=cur_level+1;
                q.push(point(rrow,ccol));
            }
        }
    }
    memset(book,0,sizeof(int)*(ROW+5)*(COL+5));
    dfs(ROW,COL); //反向深度优先搜索找回路径
    string res=strs[0];
    for(string s:strs){
        res=min(res,s);
    }
    cout<<res<<endl;
    return 0;
}

