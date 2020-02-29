#include<bits/stdc++.h> //本题考查二叉树相关计算
using namespace std;
int t[100005];
int res=-999999;
int min_depth;
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>t[i];
    }
    int cnt;
    for(int h=1;h<=ceil(log(n+1)/log(2));++h){
        cnt=pow(2,h-1);
        int sum=0;
        for(int offset=0;offset<cnt;++offset){
            int id=cnt+offset;
            sum+=t[id];
        }
        if(sum>res){
            res=sum;
            min_depth=h;
        }
    }
    cout<<min_depth<<endl;
    return 0;
}