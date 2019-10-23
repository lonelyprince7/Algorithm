#include<iostream>
using namespace std;
int N,M;
int a[100000];
inline bool judge(int k){
    int groups=1;
    int tot=0;
    for(int i=0;i<N;++i){
        if(tot<=k) tot+=a[i];
        else{
            tot=a[i];
            groups++;
        }
    } 
    return groups<=M;
}
int main(){
    cin>>N>>M;
    int l=0,r=0,mid;  //左值为数列最大值,右值为数列和
    for(int i=0;i<N;++i){
        cin>>a[i];
        l=max(l,a[i]);
        r +=a[i];
    }
    while(l<r){
        mid=(l+r)>>1;
        if(judge(mid)==1) r=mid-1;
        else l=mid+1;
    } 
    cout<<l<<endl;
    return 0;
}