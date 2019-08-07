#include<iostream>
using namespace std;
int main(){
    string p;
    string s;
    getline(cin,p);
    getline(cin,s);
    int pos=-1;
    int count=0;
    s +=' ';
    for(int i=0;i<s.length();++i){
        if(s[i]==p[0]||abs(s[i]-p[0])==32){
            int tmp=i;
            bool flag=1;
            for(int j=1;j<p.length();++j){
                i++;
                if(s[i]!=p[j]&&abs(s[i]-p[j])!=32){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                if(s[i+1]!=' '){
                    flag=0;
                }
            }
            if(flag){
                count++;
                if(pos==-1) pos=tmp;
            }
            while(s[i]!=' ') i++;
        }
        else{
            while(s[i]!=' ') i++;
        }
    }
    if(count==0) cout<<"-1"<<endl;
    if(count>0) cout<<count<<" "<<pos<<endl;
    return 0;
}