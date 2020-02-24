#include<bits/stdc++.h>
using namespace std;
class NumArray {
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        this->nums=new int[2*n];
        for(int i=n,j=0;i<2*n;++i,++j){
            this->nums[i]=nums[j];
        }
        int cur=n-1;
        while(cur>0){ 
            this->nums[cur]=this->nums[2*cur]+this->nums[2*cur+1];
            cur--;
        }
    }  
    void update(int i, int val) {
        int leaf=i+n;
        nums[leaf]=val;
        int cur=leaf/2;
        while(cur>0){
            nums[cur]=nums[2*cur]+nums[2*cur+1];
            cur/=2;
        }
    }
    int sumRange(int i, int j) {
        int l=i+n,r=j+n;
        int sum=0;
        while(l<=r){
            if(l%2==1){
                sum+=nums[l];
                l++;
            }
            if(r%2==0){
                sum+=nums[r];
                r--;
            }
            l/=2;
            r/=2;
        }  
        return sum;
    }
private:
    int* nums;
    int n;
};

int main(){
    vector<int> nums{0,1,2};
    NumArray a(nums);
    cout<<a.sumRange(0,2)<<endl;
    a.update(1,8);
    cout<<a.sumRange(0,2)<<endl;
    return 0;
}