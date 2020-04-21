#include<bits/stdc++.h>
using namespace std;
vector<int> nums{1,8,6,2,5,4,8,3,7};
int main(){
    int i=0;int j=nums.size()-1;
    int res=0;
    while(i<j){
        res=max(res,min(nums[i],nums[j])*(j-i));
        if(nums[i]<nums[j]) i++;
        else j--;
    }
    cout<<res<<endl;
    return 0;
}