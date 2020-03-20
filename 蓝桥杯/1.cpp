//本题用动态规划解决
#include<bits/stdc++.h>
using namespace std;
int res;
int book[10][10];
void dfs(int row){
   if(row>8){
       res++;
       return;
   }
   for(int col=1;col<=8;++col){
       bool flag=true;
       for(int ccol=col-1,rrow=row-1;ccol>=1&&rrow>=1 ;--ccol,--rrow){
           if(book[ccol][rrow]==1){
               flag=false;break;
           }
       }
       if(flag==true){
           book[row][col]=1;
           dfs(row+1);
           book[row][col]=0;
       }
   }
}
int main(){
    dfs(1);
    cout<<res<<endl;
    return 0;
}