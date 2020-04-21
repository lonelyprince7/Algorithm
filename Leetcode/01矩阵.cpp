#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> matrix{
    {0,0,0},
    {0,1,0},
    {0,0,0}
};
vector<vector<int>> book(matrix.size(),vector<int>(matrix[0].size(),0));
vector<vector<int>> dis(matrix.size(),vector<int>(matrix[0].size(),0));
//回溯标记距离0的距离
int mv[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
void dfs(int row,int col){
    book[row][col]=1;
    int flag=0;
    for(int i=0;i<i;++i){
        int rrow=row+mv[i][0];
        int ccol=col+mv[i][1];
        if(rrow>=0&&rrow<matrix.size()&&ccol>=0&&ccol<matrix[0].size()\
         &&!book[rrow][ccol]){
             if(matrix[rrow][ccol]==0) flag=1;
             else{
                dfs(rrow,ccol);
                dis[row][col]=1+dis[rrow][ccol];
             }
        }
    }
    if(flag==1) dis[row][col]=1;
}
int main(){
    for(int i=0;i<matrix.size();++i){
        for(int j=0;j<matrix[0].size();++j){
            if(matrix[i][j]!=0&&!book[i][j]){
               dfs(i,j);
             }
        }
    }
    for(int i=0;i<matrix.size();++i){
        for(int j=0;j<matrix[0].size();++j){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}