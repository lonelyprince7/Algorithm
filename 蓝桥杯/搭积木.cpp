#include<bits/stdc++.h>
int book[10],w[4][4];
void convert_to_index(){

}
void dfs(int cur,int row,int col){
    book[cur]=1;
    w[row][col]=cur;
    for(int i=0;i<=9;++i){
        if(!book[i]){
            if(col%2==0&&cur>w[row-1][col]){

            }
            dfs(i,)
        }
    }

}
int main(){
    for(int i=0;i<=9;++i){
        dfs(i,0,0);
    }
    return 0;
}
0
1 2
3 4 5
6 7 8 9