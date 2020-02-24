//本题考查DFS
#include<bits/stdc++.h>
using namespace std;
vector<string> res;
vector<string> Map{"_","","abc","def","ghi","jkl"\
,"mno","pqrs","tuv","wxyz"};
string s;
string tmp;
void dfs(int step){
    if(step==s.length()){
        res.push_back(tmp);
        return;
    }
    for(int i=0;i<Map[s[step]-'0'].length();++i){
        tmp+=Map[s[step]-'0'][i];
        dfs(step+1);
        tmp.erase(tmp.end()-1);
    }
}
int main(){
    cin>>s;
    dfs(0);
    for(auto s:res){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}