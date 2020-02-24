//先生成所有子集，再判断子集的连通性，取连同的子集
#include<bits/stdc++.h>
using namespace std;
int book1[13],book2[13],res;
set<int> subset;
set<set<int>> subsets;
void make_subset(int cur){
    book1[cur]=1;
    subset.insert(cur);
    if(subset.size()==5){
        subsets.insert(subset);
        book1[cur]=0;
        subset.erase(subset.find(cur));
        return;
    }
    for(int i=1;i<=12;++i){
        if(!book1[i]){
            make_subset(i);
        }
    }
    book1[cur]=0;
    subset.erase(subset.find(cur));
}
void dfs(int cur,set<int> s){
    book2[cur]=1;
    int row=(cur-1)/4,col=(cur-1)%4;
    if(row-1>=0&&!book2[(row-1)*4+col+1]&&s.find((row-1)*4+col+1)!=s.end()) dfs((row-1)*4+col+1,s);
    if(row+1<=2&&!book2[(row+1)*4+col+1]&&s.find((row+1)*4+col+1)!=s.end()) dfs((row+1)*4+col+1,s);
    if(col-1>=0&&!book2[row*4+col]&&s.find(row*4+col)!=s.end()) dfs(row*4+col,s);
    if(col+1<=3&&!book2[row*4+col+2]&&s.find(row*4+col+2)!=s.end()) dfs(row*4+col+2,s);
}
int main(){
    for(int i=1;i<=12;++i)
        make_subset(i);
    for(auto s:subsets){
        memset(book2,sizeof(book2),0);
        dfs(*s.begin(),s);bool flag=0;
        for(auto a:s){
            if(!book2[a]) flag=1;
        }
        if(flag==0) 
        {
            res++;
            // for(auto a:s){
            //     cout<<a<<" ";
            // }
            // cout<<endl;
        }
    }
    cout<<res<<endl;
    return 0;
}