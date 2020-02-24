//使用栈数据结构进行模拟
#include<iostream>
#include<stack>
using namespace std;
//打印非中间一行
void print(int& cnt,int w,int m,stack<char>& s2){
    stack<char> s1;
    for(int j=1;j<=w/2;++j){
        if(j==cnt){
            for(int k=cnt;(k<=cnt+m-1)&&(k<=w/2);++k){
                cout<<"*";
                s1.push('*');s2.push('*');
                j++;
            }
            j--;
            continue;
        }
        cout<<".";
        s1.push('.');s2.push('.');
    }
    if(w%2==1){
        if(cnt+m-1<=w/2){
            cout<<".";s2.push('.');
        }else{
            cout<<"*";s2.push('*');
        }
    }
    while(!s1.empty()){
        char c=s1.top();
        s1.pop();
        s2.push(c);
        cout<<c;
    }
    cout<<endl;
    s2.push('\n');
    cnt++;
}
//打印最中间的一行
void print(int& cnt,int w,int m){
    stack<char> s;
    for(int j=1;j<=w/2;++j){
        if(j==cnt){
            for(int k=cnt;(k<=cnt+m-1)&&(k<=w/2);++k){
                cout<<"*";
                s.push('*');
                j++;
            }
            j--;
            continue;
        }
        cout<<".";
        s.push('.');
    }
    if(w%2==1){
        if(cnt+m-1<=w/2){
            cout<<".";
        }else{
            cout<<"*";
        }
    }
    while(!s.empty()){
        char c=s.top();
        s.pop();
        cout<<c;
    }
    cout<<endl;
}
int main(){
    int m,n,w;
    while(cin>>m>>n){
        w=(m+n-1);
        int cnt=1;
        stack<char> s;
        //x上半部分
        for(int i=1;i<=n/2;++i){
            print(cnt,w,m,s);   
        }
        // 中间一行处理,此时cnt是5
        print(cnt,w,m);
        //对称的x下半部分
        s.pop(); //舍弃多余的一个换行符
        while(!s.empty()){
            char c=s.top();
            s.pop();
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}