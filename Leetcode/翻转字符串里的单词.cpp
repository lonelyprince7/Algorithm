#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="";
    string t="";
    string res="";
    vector<string> tokens;
    s="     a good   example    ";
    for(int i=0;i<s.length();++i){
        if(s[i]==' '){
            if(t!="")  tokens.push_back(t);
            t="";
        }
        else t+=s[i];
    }
    if(t!="") tokens.push_back(t);
    for(int i=tokens.size()-1;i>=0;--i){
        res+=tokens[i];
        if(i!=0) res+=" ";
    }
    cout<<res<<endl;
    return 0;
}