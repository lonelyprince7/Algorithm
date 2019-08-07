#include<iostream>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int count1=1;
    int count2=1;
    for(char c1:s1){
        count1 *=c1-'A'+1;
    }
    count1 %= 47;
    for(char c2:s2){
        count2 *=c2-'A'+1;
    }
    count2 %= 47;
    if(count1==count2) cout<<"GO"<<endl;
    else cout<<"STAY"<<endl;
    return 0;
}