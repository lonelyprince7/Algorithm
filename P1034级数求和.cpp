#include<iostream>
using namespace std;
int main(){
    int k;
    cin>>k;
    double sn=0;
    int n=0;
    while(sn<=k){
        n++;
        sn += 1.00000/n;
    }
    cout<<n<<endl;
    return 0;
}