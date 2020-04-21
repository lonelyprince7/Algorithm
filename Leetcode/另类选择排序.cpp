#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums{8,3,10,1};
    int lo,hi,imax,imin,vmax,vmin;
    lo=0;
    hi=nums.size()-1;
    while(lo<hi){
        vmin=nums[lo];
        vmax=nums[hi];
        imin=lo;
        imax=hi;
        for(int i=lo;i<=hi;++i){
            if(nums[i]>vmax){
                vmax=nums[i];
                imax=i;
            }
            if(nums[i]<vmin){
                vmin=nums[i];
                imin=i;
            }
        }
        if(imax==lo&&imin==hi){
            swap(nums[lo],nums[hi]);
        }
        else if(imax==lo){
            swap(nums[lo],nums[hi]);
            swap(nums[lo],nums[imin]);
        }
        else if(imin==hi){
            swap(nums[lo],nums[hi]);
            swap(nums[hi],nums[imax]);
        }
        else{
            swap(nums[imax],nums[hi]);
            swap(nums[imin],nums[lo]);
        }
        lo++;hi--;
    }
    for(int i=0;i<nums.size();++i){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}