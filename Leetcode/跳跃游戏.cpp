#include<bits/stdc++.h>
using namespace std;
vector<int> nums={3,2,1,0,4};
vector<int> dp(nums.size(),0);
int main(){
    bool flag=false;
    if(nums.size()==0||nums.size()==1) return 0;
    int right=nums[0];
    for(int i=1;i<nums.size();++i){
        if(i<=right){
            right=max(right,i+nums[i]);
            if(right>=nums.size()-1){
                flag=true;
                break;
            }
        }
        else{
            flag=false;
            break;
        }
    }
    if(flag==true) cout<<"can reach!"<<endl;
    else cout<<"cant reach"<<endl;
    return 0;
}