#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> obstacleGrid{
    {0},
};
int mv[2][2]={{1,0},{0,1}};
int book[3][3];
int height,width,res;
void dfs(int row,int col){
    if(obstacleGrid[row][col]==0&&row==height-1&&col==width-1){
        res++;
        return;
    }
    for(int i=0;i<2;++i){
        int rrow=row+mv[i][0];
        int ccol=col+mv[i][1];
        if(rrow>=0&&rrow<height\
        &&ccol>=0&&ccol<width&&!book[rrow][ccol]\
        &&obstacleGrid[rrow][ccol]!=1){
            book[rrow][ccol]=1;
            dfs(rrow,ccol);
            book[rrow][ccol]=0;
        }
    }
}
int main(){    
    if(obstacleGrid.size()==0) return 0;
    height=obstacleGrid.size();
    width=obstacleGrid[0].size();
    book[0][0]=1;
    dfs(0,0);
    cout<<res<<endl;
    return 0;
}