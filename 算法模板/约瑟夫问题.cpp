#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n=6; //总共人数
    int k=1; //开始的人的编号
    int m=2; //数数个数
    vector<int> a(n);
    for(int i=0;i<n;++i){
        a[i]=i+1;
    }
    int next = k-1;
    int last=0;
    while(!a.empty()){
        int i,j;
        for(i=next,j=1;j<m;i=(i+1)%a.size(),j++);
        last= a[i];
        a.erase(a.begin()+i);
        if(a.size()>0) next=i%(a.size());
        cout<<last<<endl;
    }
    cout<<last<<endl;

    return 0;
}