//本题使用分治算法
#include<bits/stdc++.h>
using namespace std;
struct ba{
    int row;
    int col;
    ba(int a,int b):row(a),col(b){}
    bool operator==(ba rhs){
        return this->row==rhs.row&&this->col==rhs.col;
    }
};
struct dist{
    int row;
    int col;
    int dis;
    dist(int a,int b,int c):row(a),col(b),dis(c){}
};
vector<vector<vector<dist>>> l;
vector<ba> v;
char nums[305][305];
int n,m;
int temp=0;
int res=99999;
int book[305][305]; 
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int row,int col){
     if(nums[row][col]=='#'){
        temp++;
        for(dist e:l[row][col]){
            if(!book[e.row][e.col]){
                temp+=e.dis;book[e.row][e.col]=1;
                dfs(e.row,e.col);
                temp-=e.dis;book[e.row][e.col]=0;
            }
        }
        for(int i=0;i<4;++i){
            int rrow=row+mv[i][0];
            int ccol=col+mv[i][1];
            if(rrow>=1&&rrow<=n&&ccol>=1&&ccol<=m\
            &&!book[rrow][ccol]&&nums[rrow][ccol]!='#'){
                book[rrow][ccol]=1;
                dfs(rrow,ccol);
                book[rrow][ccol]=0;
            }
        }
        temp--;
     }else{
        if(row==n&&col==m){
            res=min(res,temp);
            return;
        }
        for(int i=0;i<4;++i){
            int rrow=row+mv[i][0];
            int ccol=col+mv[i][1];
            if(rrow>=1&&rrow<=n&&ccol>=1&&ccol<=m\
            &&!book[rrow][ccol]){
                book[rrow][ccol]=1;
                dfs(rrow,ccol);
                book[rrow][ccol]=0;
            }
        }
    }
}
int main(){
    for(int i=0;i<305;++i){
        vector<vector<dist>> t1;
        l.push_back(t1);
        for(int j=0;j<305;++j){
            vector<dist> t2;
            l[i].push_back(t2);
        }
    }
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>nums[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(nums[i][j]=='#'\
            &&(nums[i][j-1]=='.'||nums[i][j+1]=='.'\
            ||nums[i-1][j]=='.'||nums[i+1][j]=='.')){
                v.push_back(ba(i,j));
            }
        }
    }
    for(ba elem1:v){
        for(ba elem2 :v){
            if(!(elem2==elem1)){
                int distance=abs(elem1.col-elem2.col)\
                +abs(elem1.row-elem2.row);
                l[elem1.row][elem1.col].push_back\
                (dist(elem2.row,elem2.col,distance));
            }
        }
    }
    // for(dist e:l[2][2]){
    //     cout<<e.row<<" "<<e.col<<" "<<e.dis<<endl;
    // }
    book[1][1]=1;
    dfs(1,1);
    cout<<res<<endl;
    return 0;
}