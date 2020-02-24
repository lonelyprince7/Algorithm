//本题采用BFS解决
#include<bits/stdc++.h>
using namespace std;
struct info{
    int nums[9];
    int index; //专门记录空被子是哪一号
    int cnt;
};
bool book[10][10][10][10][10][10][10][10][10];
queue<info> q;
int mv[4]={-2,-1,1,2};
int main(){
    info cur;
    for(int i=0;i<=8;++i) cur.nums[i]=i;
    cur.cnt=cur.index=0;
    q.push(cur);
    book[cur.nums[0]][cur.nums[1]][cur.nums[2]]\
    [cur.nums[3]][cur.nums[4]][cur.nums[5]]\
    [cur.nums[6]][cur.nums[7]][cur.nums[8]]=1;
    int res=999;
    while(!q.empty()){
        info cur=q.front();
        q.pop();
        if(cur.nums[0]==0&&cur.nums[1]==8&&cur.nums[2]==7\
          &&cur.nums[3]==6&&cur.nums[4]==5&&cur.nums[5]==4\
          &&cur.nums[6]==3&&cur.nums[7]==2&&cur.nums[8]==1){
              res=min(res,cur.cnt);
        }
        for(int i=0;i<4;++i){
            info t=cur;
            swap(t.nums[(t.index+mv[i]+9)%9],t.nums[t.index]);
            t.index=(t.index+mv[i]+9)%9;
            t.cnt=cur.cnt+1;
            if(!book[t.nums[0]][t.nums[1]][t.nums[2]]\
                [t.nums[3]][t.nums[4]][t.nums[5]]\
                [t.nums[6]][t.nums[7]][t.nums[8]]){
                q.push(t);
                book[t.nums[0]][t.nums[1]][t.nums[2]]\
                [t.nums[3]][t.nums[4]][t.nums[5]]\
                [t.nums[6]][t.nums[7]][t.nums[8]]=1;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}