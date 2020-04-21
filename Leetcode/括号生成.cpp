#include<bits/stdc++.h>
using namespace std;
vector<string> res;
string t;
int n=4;
void dfs(int left,int right){
    if(left<right){
        //括号之间的间隙在哪个的前面
        for(int i=left;i<=right;i+=1){
            if(i==left||i==right){
                //没有间隙
                t[left]='('; t[right]=')';
                dfs(left+1,right-1);
            }
            else{
                t[left]='#';t[right]='#'; 
                dfs(left,i-1);
                dfs(i,right);
            }
        }
    }
    else if(left==right) return;
    else{
        if(t.find('#')==string::npos&&\
        find(res.begin(),res.end(),t)==res.end()) res.push_back(t);
    }
}
int main(){
    t.resize(2*n,'#');
    dfs(0,2*n-1);
    int cnt=0;
    sort(res.begin(),res.end());
    for(auto s:res){
        cnt++;
        cout<<s<<" "<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}