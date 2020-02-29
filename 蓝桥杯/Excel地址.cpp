//本题考查权值单位换算问题
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    while(cin>>n){
        vector<char> s;
        while(n){
            int z=n%26;
            if(z==0){
                s.push_back('Z');
                n =(n-1)/26;
            }
            else{
                int t=z-1+(int)'A';
                s.push_back((char)t);
                n/=26;
            }
        }
        for(int i=s.size()-1;i>=0;--i){
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}