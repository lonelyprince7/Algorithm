#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(s2.length()==0){
        cout<<"yes"<<endl;
        return 0;
    }
    if(s1.length()==0){
        cout<<"no";
        return 0;
    }
    s1.erase(unique(s1.begin(),s1.end()),s1.end());
    bool flag=1;
    int j=0;
    for(int i=0;i<s2.length();++i){
        while(s1[j]!=s2[i]&&j<s1.length()) j++;
        if(j==s1.length()) flag=0;
    }
    if (flag==0) cout<<"no"<<endl;
    else cout<<"yes"<<endl;

    return 0;
}