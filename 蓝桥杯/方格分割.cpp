#include<iostream>
using namespace std;
int cnt,book[6][6],res;
void dfs(int row,int col){
    book[row][col]=1;cnt++;
    if(book[6-row][6-col]){
        book[row][col]=0;cnt--;return;
    }
    if(cnt==18){ 
        res++;book[row][col]=0;cnt--;return;
    }
    if(row-1>=0&&!book[row-1][col]) dfs(row-1,col);
    if(row+1<6&&!book[row+1][col]) dfs(row+1,col);
    if(col-1>=0&&!book[row][col-1]) dfs(row,col-1);
    if(col+1<6&&!book[row][col+1]) dfs(row,col+1);
    book[row][col]=0;cnt--;
}
int main(){
    for(int i=0;i<6;++i){
        for(int j=0;j<6;++j){
            dfs(i,j);
        }
    }
    cout<<res/4<<endl;
    return 0;
}
// #include<stdio.h>
// #include<string.h>
// #define N 6

// int vis[N+1][N+1],ans=0,d[4][2]={0,1,1,0,0,-1,-1,0};

// int dfs(int x,int y){
//     int i,x1,y1;
//     if(x==0||y==0||x==N||y==N){
//         ans++;
//         return 0;
//     }
//     else{
//         for(i=0;i<4;i++){//向四个方向进行深度搜索          
//             x1=x+d[i][0];
//             y1=y+d[i][1];
//             if(vis[x1][y1]==0){//该点必须没有被搜索过 
//                 vis[x1][y1]=1;
//                 vis[N-x1][N-y1]=1;
//                 dfs(x1,y1);//深搜 
//                 vis[x1][y1]=0;//恢复，返回上一层 
//                 vis[N-x1][N-y1]=0;
//             }   
//         }
//     }
// }

// int main(){
//     memset(vis,0,sizeof(vis));
//     vis[3][3]=1;
//     dfs(3,3);
//     printf("%d",ans/4); 
//     return 0;
// } 
