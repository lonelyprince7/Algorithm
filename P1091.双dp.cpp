#include<iostream>
using namespace std;
int a[105];
int increase[105];
int decrease[105];
int N;
int func_increase(int t){
    int max_val=0;
    for(int i=1;i<=t;++i){
        increase[i]=1;
        for(int j=1;j<=i-1;++j){
            if(a[j]<a[i]){
                increase[i]=max(increase[i],increase[j]+1);
            }
        }
        max_val=max(max_val,increase[i]);
    }
    return max_val;
}
int func_decrease(int t){
    int max_val=0;
    for(int i=t+1;i<=N;++i){
        decrease[i]=1;
        for(int j=t+1;j<=i-1;++j){
            if(a[j]>a[i]){
                decrease[i]=max(decrease[i],decrease[j]+1);
            }
        }
        max_val=max(max_val,decrease[i]);
    }
    return max_val;
}
int main(){
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>a[i];
    }
    int min_sum=-999;
    int max_increase, max_decrease,rest,max_sum;
    for(int t=1;t<=N-1;++t){
        max_increase=func_increase(t);
        max_decrease=func_decrease(t);
        max_sum=max(max_sum,max_increase+max_decrease);
    }
    std::cout<<N-max_sum<<endl;
    return 0;
}