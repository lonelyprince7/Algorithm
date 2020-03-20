//本题使用分治算法
#include<bits/stdc++.h>
using namespace std;
struct elem{
    long long height;
    elem(long long a):height(a){}
};
long long n,k,height,width;
vector<elem> elems;
int main(){
    cin>>k>>n;
    long long max_size=999;
    elems.clear();
    for(long long i=0;i<n;++i){
        cin>>height;
        max_size=max(max_size,height); //注意不是minheight，min weight，特殊情况比如1*1的直接不要了
        elems.push_back(elem(height));
    }
    long long mid,res=-1;
    long long low=1,high=max_size;  //反正巧克力最大为max_size,要确定合适的巧克力大小
    while(low<=high){
        mid=(low+high)/2;
        long long sum=0;
        for(long long i=0;i<n;++i){
            sum+=(elems[i].height/mid);
            if(sum>=k) break; //剪枝
        }
        if(sum>=k){
            res=max(res,mid);
            low=mid+1;
        }
        if(sum<k) high=mid-1;
    }
    cout<<res<<endl;
    return 0;
}