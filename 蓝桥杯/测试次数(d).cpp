#include<bits/stdc++.h> //动态规划 
using namespace std;
int main(){
    int target=1;
    int left=1;
    int right=1000;
    int cnt=0;
    while(left<=right){
        int mid=(left+right)/2;
        cnt++;
        if(mid==target) break;
        if(mid<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<cnt<<endl;

    return 0;
}
