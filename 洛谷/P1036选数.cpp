#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
int n,k;
vector<int> group;
vector<vector<int>> groups;
bool isprime(int num){
    if(num<=1) return 0;
    for(int i=2;i<num/2;++i){
        if(num%i==0) return 0;
    }
    return 1;
}
void dfs(int a[],int index){
    group.push_back(a[index]);
    if(group.size()==k){
        groups.push_back(group);
        return;
    }
    for(int i=index+1;i<n;++i){
        dfs(a,i);
        group.pop_back();
    }
}
int main(){
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        dfs(a,i);
        group.pop_back();
    }
    int count=0;
    for(int i=0;i<groups.size();++i){
        int sum=accumulate(groups[i].begin(),groups[i].end(),0);
        if(isprime(sum)) count++;
    }
    cout<<count<<endl;
    return 0;
}