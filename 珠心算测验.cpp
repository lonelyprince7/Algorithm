#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;++i){
        int tmp;
        cin>>tmp;
        nums.push_back(tmp);
    }
    int count=0;
    sort(nums.begin(),nums.end());
    int lo,hi;
    for(int i=0;i<n;++i){
        lo=0;
        hi=n-1;
        while(lo<hi){
            if(nums[lo]+nums[hi]>nums[i]){
                hi--;
            }        
            else if(nums[lo]+nums[hi]<nums[i]){
                lo++;
            }
            else{
                count++;
                break;
            }
        }
    }
    cout<<count<<endl; 
    return 0;
}