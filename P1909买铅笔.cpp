#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    float pen;
    float nums[3];
    int price[3];
    cin>>pen;
    for(int i=0;i<3;++i){
        cin>>nums[i]>>price[i];
    }
    int res=ceil(pen/nums[0])*price[0];
    for(int i=1;i<3;++i){
        res = ceil(pen/nums[i])*price[i]<res?ceil(pen/nums[i])*price[i]:res;
    }
    cout<<res<<endl;
    return 0;
}