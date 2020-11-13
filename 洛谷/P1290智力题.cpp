#include<iostream>
using namespace std;
int pre,cur,sum;
int main(){
    for(int i=1;i<=100;++i){
        cur=i+pre;
        sum+=cur;
        pre=cur;
    }
    cout<<sum<<endl;
    return 0;
}