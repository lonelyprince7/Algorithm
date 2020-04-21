#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> grid{
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
};
vector<vector<int>> book;
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int row,int col){
    book[row][col]=1;
    for(int i=0;i<4;++i){
        int rrow=row+mv[i][0];
        int ccol=col+mv[i][1];
        if(rrow>=0&&ccol>=0&&rrow<grid.size()&&ccol<grid[0].size()\
        &&!book[rrow][ccol]&&grid[rrow][ccol]=='1'){
            dfs(rrow,ccol);
        }
    }
}
int main(){
    book.resize(grid.size(),vector<int>(grid.size(),0));
    int res=0;
    for(int i=0;i<grid.size();++i){
        for(int j=0;j<grid[0].size();++j){
            if(!book[i][j]&&grid[i][j]=='1'){
                res++;
                dfs(i,j);
            }
        }
    }
    cout<<res<<endl;

    return 0;
}