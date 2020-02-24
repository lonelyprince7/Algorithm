#include<bits/stdc++.h> //本题采用解决双端队列解决
using namespace std;
int main(){
    int n;
    while(cin>>n){
        //顶点1单独放
        deque<int> q1;//存放数字序列
        queue<int> q2;//待加入数字序列
        int cnt=2; //当前数到哪个数了
        q2.push(2);
        while(q1.size()<4*n-5){
            int cur=q2.front();q2.pop();q1.push_back(cur);
            int nxt=cnt+1;cnt++;
            stack<int> t;//提取每一位数字
            while(nxt){
                t.push(nxt%10);
                nxt/=10;
            }
            while(!t.empty()){
                q2.push(t.top());
                t.pop();
            }
        }
        //先把第一行打印
        for(int i=1;i<=n-1;++i) cout<<".";cout<<"1"<<endl;
        //打印中间n-2行
        for(int i=2;i<=n-1;++i){
            for(int j=1;j<=n-i;++j) cout<<".";//打印'.'
            cout<<q1.front();q1.pop_front();
            for(int j=1;j<=2*i-3;++j) cout<<".";
            cout<<q1.back();q1.pop_back();
            cout<<endl;
        }
        //最后一行按顺序打印q1剩余部分即可
        for(int i:q1) cout<<i;cout<<endl;
    }
    return 0;
}