#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans=s.length();
    int k;
    string substr="";
    substr+=s[0];
    for(int i=1;i<s.length();++i){
        if(s[i]!=s[0]) substr+=s[i];
        else{
            k=i;
            if(s.length()%k==0){
                bool flag=1;
                for(int j=i+1;j<s.length();++j){
                    if(substr[j%k]!=s[j]){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    ans=k;
                    break;
                }
                else{
                    substr+=s[i];
                    continue;
                }
            }
            else{
                substr+=s[i];
                continue;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}