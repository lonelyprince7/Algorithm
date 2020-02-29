//本题考查栈的应用
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    stack<char> s;
    for(int i=0;i<str.length();++i){
        if(str[i]==')'){
            char top=s.top();
            s.pop();
            int l=0;int r=0;
            bool flag=0;
            while(top!='('){
                if(top=='|') flag=1;
                else if(top=='x'&&flag==0) r++;
                else if(top=='x'&&flag==1) l++;
                top=s.top();
                s.pop();
            }
            for(int i=1;i<=max(l,r);++i){
                s.push('x');
            }
        }
        else s.push(str[i]);

    }
    cout<<s.size()<<endl;
    return 0;
}