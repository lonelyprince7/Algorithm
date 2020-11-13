/*
 * @Descripttion: 
 * @Version: 1.0
 * @Author: ZhangHongYu
 * @Date: 2020-11-09 21:07:18
 * @LastEditors: ZhangHongYu
 * @LastEditTime: 2020-11-09 21:23:55
 */
#include<iostream>
using namespace std;
int main(){
    int nums[5]={1,3,4,6,7};
    int l=0;
    int r=4;
    int mid;
    int t=3;
    while(l<r){
        mid=(l+r)/2;
        if(nums[mid]>t) r=mid;
        else l=mid+1;
    } //最后一次l<r，取下界l，r就不能-1，否则会造成l==r进不了循环
    // while(l<=r){
    //     mid=(l+r)/2;
    //     if(nums[mid]>t) r=mid-1;
    //     else l=mid+1;
    // } 最后一次l==r，可以进入循环恰好夹住
    cout<<nums[mid]<<endl;
    return 0;
}