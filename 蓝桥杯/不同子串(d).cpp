//本题考查Fiboccani闭公式,但double位数不够放不下
#include<bits/stdc++.h>
using namespace std;
vector<string> a;//储存所有位串组合
string mask;
int res;
void dfs(int step){
    if(step>16){
        string t;
        for(int b:mask){
            if(b-'0') t+=
        }
        return;
    }
    mask+='0';
    dfs(step+1);
    mask.pop_back();
    mask+='1';
    dfs(step+1);
    mask.pop_back();
}
int main(){
    string s="0100110001010001";
    dfs(1);
    cout<<a.size()<<endl;
    for(string t:a){
        if(s.find(t)!=string::npos) res++;
    }
    cout<<res<<endl;
    return 0;
}