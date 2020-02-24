#include<bits/stdc++.h> //本题考查滑动窗口统计区间量(双端队列)
using namespace std;
vector<vector<int>> a;
set<int> book;//标记出现过的id
int main(){//本题考查矩阵的行优先存放形式
    int n,d,k,t,id;
    cin>>n>>d>>k;
    a.resize(100005);
    for(int i=0;i<n;++i){
        cin>>t>>id;
        a[id].push_back(t);
        book.insert(id);
    }
    for(auto i:book){
        sort(a[i].begin(),a[i].end());
        deque<int> win;
        size_t max_size=0;
        for(int j:a[i]){
            win.push_back(j);
            if(j-win[0]>=d) win.pop_front();
            max_size=max(win.size(),max_size);
        }
        if(max_size>=k) cout<<i<<endl;
    }
    return 0;
}