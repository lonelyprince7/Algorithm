#include<bits/stdc++.h>//本题为BFS典型例题
using namespace std;
int main(){
    vector<vector<char>> board
    {{'E', 'E', 'E', 'E', 'E'},
    {'E', 'E', 'M', 'E', 'E'},
    {'E', 'E', 'E', 'E', 'E'},
    {'E', 'E', 'E', 'E', 'E'}};
    vector<int> click{3,0};
    int height=board.size();
    int width=board[0].size();
    queue<vector<int>> q;
    q.push(click);
    while(!q.empty()){
        vector<int> cur= q.front();
        q.pop();
        if(board[cur[0]][cur[1]]=='M'){
            board[cur[0]][cur[1]]='X';
            break;
        }
        if(board[cur[0]][cur[1]]=='E'){
            int flag=0;int cnt=0;
            for(int x=-1;x<=1;++x){
                for(int y=-1;y<=1;++y){
                    if(x==0&&y==0) continue;
                    if(cur[0]+x>=0&&cur[0]+x<height&&cur[1]+y>=0&&cur[1]+y<width){
                        if(board[cur[0]+x][cur[1]+y]=='M'){
                            cnt++;flag=1;
                        }

                    }
                }
            }
            if(flag!=1){
                for(int x=-1;x<=1;++x){
                    for(int y=-1;y<=1;++y){
                        if(x==0&&y==0) continue;
                        if(cur[0]+x>=0&&cur[0]+x<height&&cur[1]+y>=0&&cur[1]+y<width){
                            if(flag!=1&&board[cur[0]+x][cur[1]+y]=='E'){
                                vector<int> next{cur[0]+x,cur[1]+y};
                                q.push(next);
                            }
                        }
                    }
                }
                board[cur[0]][cur[1]]='B';
            }
            if(flag==1) board[cur[0]][cur[1]]=cnt+'0';      
        }
    }
    for(auto v1:board){
        for(auto v2:v1){
            cout<<v2<<" ";
        }
        cout<<endl;
    }
    return 0;
}