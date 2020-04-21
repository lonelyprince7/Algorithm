#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> board={
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    vector<vector<int>> res=board;
    int mv[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    for(int i=0;i<board.size();++i){
        for(int j=0;j<board[0].size();++j){
            int die=0;int live=0;
            for(int k=0;k<8;++k){
                int x=i+mv[k][0];
                int y=j+mv[k][1];
                if(0<=x&&x<board.size()&&0<=y&&y<board[0].size()){
                    if(board[x][y]==0) die++;
                    else live++;
                }
            }
            if(board[i][j]==0){
                if(live==3) res[i][j]=1;
                else res[i][j]=0;
            }
            else{
                if(live<2) res[i][j]=0;
                else if(live==2||live==3) res[i][j]=1;
                else if(live>3) res[i][j]=0;
            }
        }
    }
    for(int i=0;i<board.size();++i){
        for(int j=0;j<board[0].size();++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}