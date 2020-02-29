#include<bits/stdc++.h>
using namespace std;
bool contain(int n){
    while(n){
        if(n%10==2||n%10==4){
            return true;
        }
        n/=10;
    }
    return false;
}
set<vector<int>> res;
int main(){
    for(int i=1;i<=2019;++i){
        int t1=2019-i;
        for(int j=1;j<=t1;++j){
            int t2=t1-j;
            if(t2>=1&&!contain(i)&&!contain(j)&&!contain(t2)&&i!=j&&j!=t2&&i!=t2){
                vector<int> vec={i,j,t2};
                sort(vec.begin(),vec.end());
                res.insert(vec);
            }
        }
    }
    cout<<res.size()<<endl;
    return 0;
}