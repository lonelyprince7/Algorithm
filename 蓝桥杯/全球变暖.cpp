#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int book[1005][1005];
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,cnt,res;
void dfs(int i,int j){
    bool flag=1;
    for(int p=0;p<4;++p){
        if(a[d[p][0]+i][d[p][1]+j]=='#'&&!book[d[p][0]+i][d[p][1]+j]){
            book[d[p][0]+i][d[p][1]+j]=1;
            dfs(d[p][0]+i,d[p][1]+j);
        }
        if(a[d[p][0]+i][d[p][1]+j]=='.') flag=0; 
    }
    if(flag==1) cnt++;
}

int main(){ //本题用 dfs解决
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        getchar();
        for(int j=0;j<n;++j){
            scanf("%c",&a[i][j]);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(a[i][j]=='#'&&!book[i][j]){
                cnt=0;
                book[i][j]=1;
                dfs(i,j);
                if(cnt>0) res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}

// .......
// .......
// .##....
// ...###.
// ..####.
// ...###.
// .......