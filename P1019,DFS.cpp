#include<iostream>
#include<vector>
#include<string>
using namespace std;
int book[21];
int max_val,n;
char head;
string tmp;
vector<string> strs;
void dfs(char pre,int cnt){
    max_val=cnt>max_val?cnt:max_val;
    for(int i=0;i<n;++i){
        if(strs[i][0]==pre&&book[i]<2){
            book[i]++;
            dfs(strs[i][strs[i].length()-1],cnt+strs[i].length()-1);
            book[i]--;
        }
    } 
}
int main(){
    cin>>n;
    strs.reserve(21);
    for(int i=0;i<n;++i){
        cin>>tmp;
        strs.push_back(tmp);
    }
    cin>>head;
    for(int i=0;i<n;++i){
        if(strs[i][0]==head){
            book[i]++;
            dfs(strs[i][strs[i].length()-1],strs[i].length());
            book[i]--;
        }
    }
    cout<<max_val<<endl;
    return 0;
}