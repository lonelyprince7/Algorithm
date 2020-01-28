#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> prices{7,6,4,3,1};
    int res=0;
    for(int i=0;i<prices.size()-1;++i){
        if(prices[i]<prices[i+1]){
            res+=prices[i+1]-prices[i];
        }
    }
    cout<<res<<endl;
    return 0;
}