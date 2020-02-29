//本题采用BFS解决,
//技巧在于用一个字符串储存当前场上状态,将空白看为实际移动物
#include<bits/stdc++.h>
using namespace std;
struct info{
    string s;
    int step;
    info(string a,int b):s(a),step(b){}
};
int mv[6]={-3,-2,-1,1,2,3};
set<string> book;
int main(){
    string s1,s2;
    while(cin>>s1){
        cin>>s2;
        info cur(s1,0);
        queue<info> q;
        q.push(cur);
        book.insert(cur.s);
        int res=999;
        while (!q.empty())
        {
            info cur=q.front();q.pop();
            if(cur.s==s2){
                res=min(res,cur.step);
            }
            int index=cur.s.find('*');
            for(int i=0;i<6;++i){
                if(index+mv[i]>=0&&index+mv[i]<cur.s.length()){
                    info t=cur;
                    swap(t.s[index+mv[i]],t.s[index]);
                    t.step++;
                    if(book.count(t.s)==0){
                        q.push(t);
                        book.insert(t.s);
                    }
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}