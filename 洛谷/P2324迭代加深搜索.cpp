#include<iostream>
using namespace std;
int a[6][6];
int mod[6][6]={
   {0,0,0,0,0,0},
   {0,1,1,1,1,1},
   {0,0,1,1,1,1},
   {0,0,0,-1,1,1},
   {0,0,0,0,0,1},
   {0,0,0,0,0,0}
};
void dfs(int i,int j,int step,int depth){
    bool b=true;
    for(int i=1;i<=5;++i){
        for(int j=1;j<=5;++j){
            if(mod[i][j]!=a[6][6])
                b=false;
        }
    }
    if(b=true){
        step=depth;
        return ;
    }
    for(int i=1;i<=5;++i){
        for(int j=1;j<=5;++j){
            {
                dfs()
                dfs
                dfs
                dfs
                dfs
                dfs
                dfs
                dfs
            }
            dfs(i,j,step,depth+1);
        }
    }
}
int main(){
    int n;
    char tmp;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int i=1;i<=5;++i){
            for(int j=1;j<=5;++j){
                cin>>tmp;
                if(tmp='*') a[i][j]=-1;
                else a[i][j]=tmp-'0';
            }
        }
    }
    int i,j=1;
    int step,depth=0;
    dfs(i,j,step,depth);
    return 0;
}