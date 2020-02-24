#include<bits/stdc++.h>
using namespace std; //本题采用BFS解决
struct state{
    int a_row;int a_col;
    int b_row;int b_col;
    int c_row;int c_col;
    int cnt;
};
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int book[5][5][5][5][5][5];
int main(){
    string s1,s2;
    while(getline(cin,s1)){
        getline(cin,s2);string s3=s1+s2;
        memset(book,0,sizeof(int)*pow(5,6));
        queue<state> q;state s;
        for(int i=0;i<6;++i){
            if(s3[i]==' '){
                s.c_row=i/3;s.c_col=i%3;
            }
            if(s3[i]=='A'){
                s.a_row=i/3;s.a_col=i%3;
            }
            if(s3[i]=='B'){
                s.b_row=i/3;s.b_col=i%3;
            }
        }
        s.cnt=0;int res=999;
        q.push(s);book[s.a_row][s.a_col][s.b_row][s.b_col][s.c_row][s.c_col]=1;
        int e_a_row=s.b_row;int e_a_col=s.b_col; //结尾满足条件的a,b坐标
        int e_b_row=s.a_row;int e_b_col=s.a_col;
        while(!q.empty()){
            state s=q.front();q.pop();
            if((s.a_row==e_a_row)&&(s.a_col==e_a_col)\
            &&(s.b_row==e_b_row)&&(s.b_col==e_b_col)){
                res=min(s.cnt,res);
            }
            for(int i=0;i<4;++i){
                state cur=s;
                if((0<=cur.c_row+mv[i][0])&&(cur.c_row+mv[i][0]<=1)\
                &&(0<=cur.c_col+mv[i][1])&&(cur.c_col+mv[i][1])<=2){
                    if((cur.a_row==cur.c_row+mv[i][0])\
                    &&(cur.a_col==cur.c_col+mv[i][1])){
                        swap(cur.a_row,cur.c_row);
                        swap(cur.a_col,cur.c_col);
                    }
                    else if((cur.b_row==cur.c_row+mv[i][0])\
                    &&(cur.b_col==cur.c_col+mv[i][1])){
                        swap(cur.b_row,cur.c_row);
                        swap(cur.b_col,cur.c_col); 
                    }else{
                        cur.c_row=cur.c_row+mv[i][0];
                        cur.c_col=cur.c_col+mv[i][1];
                    }
                }
                if(!book[cur.a_row][cur.a_col][cur.b_row]\
                [cur.b_col][cur.c_row][cur.c_col]){
                    cur.cnt=s.cnt+1;
                    q.push(cur);  
                    book[cur.a_row][cur.a_col][cur.b_row]\
                    [cur.b_col][cur.c_row][cur.c_col]=1;
                }
            }
        }
        cout<<res<<endl;        
    }
    return 0;
}