//DFS
#include<bits/stdc++.h>
using namespace std;
int w[3][4],cnt,ans;
int used[10];
void dfs(int row,int col){
    for(int k=0;k<10;++k){
        if(!used[k]){
            bool flag=true;
            for(int i=-1;i<=1;++i){
                for(int j=-1;j<=1;++j){
                    if((row+i>=0)&&(row+i<=2)&&(col+j>=0)&&(col+j<=3)){
                        if((k==w[row+i][col+j]+1)||(k==w[row+i][col+j]-1))flag=false;
                    }
                }
            }
            if(flag==true){
                w[row][col]=k;used[k]=1;cnt++;
                if(cnt==10) ans++;
                if (row==0&&col<=2) dfs(row,col+1);
                else if(row==0&&col==3) dfs(row+1,col);
                else if(row==1&&col>=1) dfs(row,col-1);
                else if(row==1&&col==0) dfs(row+1,col);
                else if(row==2&&col<=1) dfs(row,col+1);
                used[k]=0;w[row][col]=-2;cnt--;
            }   
        }
    }
}
int main(){
    for(int i=0;i<3;++i){
        for(int j=0;j<4;++j){
            w[i][j]=-2;
        }
    }
    dfs(0,1);
    cout<<ans<<endl;
    return 0;
}