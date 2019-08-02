#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    char ch;
    cin>>n>>ch;
    string str="";
    for(int i=1;i<=n;++i){
        str += to_string(i);
    }
    int count=0;
    for(auto i=str.begin();i<str.end();i++){
        if(*i==ch) count++;
    }
    cout<<count<<endl;
    return 0;
}