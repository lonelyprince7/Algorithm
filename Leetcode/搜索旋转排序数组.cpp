#include<bits/stdc++.h> //本题考查分治思想
using namespace std;
bool flag=false;
void func(vector<int>& nums,int lo,int hi,int target){
    if(lo<=hi){
        int mid=(lo+hi)/2;
        if(nums[mid]==target){
            flag=true;
            return;
        }
        if(nums[lo]<=target&&nums[mid]>=target) func(nums,lo,mid-1,target);
        if(nums[lo]>=target&&nums[mid]>=target) func(nums,mid+1,hi,target);
        if(nums[lo]<=target&&nums[mid]<=target) func(nums,mid+1,hi,target);
        if(nums[lo]>=target&&nums[mid]<=target) func(nums,mid+1,hi,target);
    }
}
int main(){
    vector<int> nums{2,5,6,0,0,1,2};
    func(nums,0,nums.size()-1,0);
    if(flag==true) cout<<"true"<<endl;
    else cout<<"flase"<<endl;
    return 0;
}