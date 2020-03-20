//本题用动态规划解决
#include<bits/stdc++.h>
using namespace std;
int alice,bob,ping,n;
string a,b;
int main(){
    cin>>n;
    cin>>a;cin>>b;
    for(int i=0;i<a.length();++i){
        if(a[i]==b[i]){
            ping++;
        }
        else{
            if(a[i]=='S'&&b[i]=='R'){
                bob++;
            }
            if(a[i]=='S'&&b[i]=='P'){
                alice++;
            }
            if(a[i]=='R'&&b[i]=='S'){
                alice++;
            }
            if(a[i]=='R'&&b[i]=='P'){
                bob++;
            }
            if(a[i]=='P'&&b[i]=='S'){
                bob++;
            }
            if(a[i]=='P'&&b[i]=='R'){
                alice++;
            }
        }
    }
    cout<<alice<<" "<<bob<<" "<<ping<<endl;
    return 0;
}