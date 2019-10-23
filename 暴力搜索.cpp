#include<iostream>
using namespace std;
int map[10]={6,2,5,5,4,5,6,3,7,6};
int match(int n){
    if(n==0) return 6;
    int count=0;
    while(n){
        count +=map[n%10];
        n/=10;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    int count=0;
    for(int i=0;i<=1000;++i){
        for(int j=0;j<=1000;++j){
            if(match(i)+match(j)+match(i+j)==n-4)
                count++;
        }
    }
    cout<<count<<endl;
    return 0;
}