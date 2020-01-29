#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n,base;
    stack<char> s;
    cin>>n>>base;
    cout<<n<<"=";
    while(n){
        int mod=n%base;
        if(mod<0){
            mod -= base;
            n = n/base+1;
        }
        else n/=base;
        if(mod<10) s.push('0'+mod);
        else s.push('A'+mod-10);
    }
    while(!s.empty()){
        char n=s.top();
        cout<<n;
        s.pop();
    }
    cout<<"(base"<<base<<")";
    system("pause");
    return 0;
}

