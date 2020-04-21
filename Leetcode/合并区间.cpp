#include<bits/stdc++.h>
using namespace std;
struct range{
    int left;
    int right;
    range(int a,int b):left(a),right(b){}
};
bool operator<(range l,range r){
    return l.left<r.left;
}
vector<vector<int>> nums{
    {1,4},{4,5}
};
vector<int> book(nums.size(),0);
int Find(int cur){
    if(cur==book[cur]) return cur;
    else return Find(book[cur]); 
}
void Union(int pre,int cur){
    book[cur]=Find(pre);
}
int main(){
    vector<range> rnums;
    vector<vector<int>> res;
    for(int i=0;i<book.size();++i) book[i]=i;
    for(int i=0;i<nums.size();++i){
        rnums.push_back(range(nums[i][0],nums[i][1]));
    }
    if(rnums.size()==0||rnums.size()==1) return 0;
    sort(rnums.begin(),rnums.end());
    for(int i=1;i<rnums.size();++i){
        if(rnums[Find(i-1)].right<rnums[i].left) continue;
        else{
            Union(i-1,i);
            int r=book[i];
            rnums[r].right=max(rnums[r].right,rnums[i].right);
            rnums[r].left=min(rnums[r].left,rnums[i].left);
        }
    }
    for(int i=0;i<book.size();++i){
        if(book[i]==i){
            res.push_back(vector<int>{rnums[i].left,rnums[i].right});
        }
    }
    for(int i=0;i<res.size();++i){
        for(int j=0;j<2;++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}