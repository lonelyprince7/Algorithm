#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long res=1;
    for(int i=1;i<=n;++i){
        res *=i;
        while(res%10==0){
            res /=10;
        }
        res %=10000000;
    }
    cout<<res%10<<endl;
    return 0;
}