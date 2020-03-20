#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums1{1};
    vector<int> nums2{};
    vector<int> nums3(nums1.size()+nums2.size(),0);
    int i=0;
    int j=0;
    int k=0;
    while(i!=nums1.size()&&j!=nums2.size()){
        if(nums1[i]<nums2[j]) nums3[k++]=nums1[i++];
        else nums3[k++]=nums2[j++];
    }
    while(i!=nums1.size()) nums3[k++]=nums1[i++];
    while(j!=nums2.size()) nums3[k++]=nums2[j++];
    for(int a:nums3){
        cout<<a<<" ";
    }
    cout<<endl;
    if(nums3.size()%2==0)\
        printf("%.1f",(nums3[(nums3.size()-1)/2]+nums3[(nums3.size())/2])/2.0);
    else
        printf("%.1f",nums3[nums3.size()/2]*1.0);
    return 0;
}