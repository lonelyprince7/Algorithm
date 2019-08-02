#include<iostream>
using namespace std;
int main(){
    int output[12];
    for(int i=0;i<12;++i){
        cin>>output[i];
    }
    int cur=0;
    int sum=0;
    for(int i=0;i<12;++i){
        cur +=300;
        if(cur-output[i]>=100){
            cur -= output[i];
            sum +=cur-(cur%100);
            cur =cur%100;
        }
        else if(cur-output[i]>=0&&cur-output[i]<100){
            cur -=output[i];
        }
        else{
            cout<<"-"<<i+1<<endl;
            return 0;
        }
    }
    cout<<sum*1.2+cur<<endl;
    return 0;
}