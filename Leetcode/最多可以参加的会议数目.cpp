#include<bits/stdc++.h> //贪心算法
using namespace std;
struct p{
    int s;
    int t;
    p(int a,int b):s(a),t(b){}
    bool operator<(p rhs){
        return this->t<rhs.t;
    }
};
int main(){
    vector<vector<int>> events={{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7}};
    if(events.size()==0) return 0;
    vector<p> nums;
    for(int i=0;i<events.size();++i){
        nums.push_back(p(events[i][0],events[i][1]));
    }
    sort(nums.begin(),nums.end());
    map<int ,int> m;
    int res=0;
    for(int i=0;i<nums.size();++i){
        for(int j=nums[i].s;j<=nums[i].t;++j){
            if(!m[j]){
                res++;
                m[j]=1;
                break;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}