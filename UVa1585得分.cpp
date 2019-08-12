#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int count=0;
    int sum=0;
    for(int i=0;i<s.length();++i){
        if(s[i]=='X') count=0;
        else sum += ++count;
    }
    cout<<sum;
    return 0;
}
