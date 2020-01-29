#include<iostream>
#include<set>
#include<sstream>
using namespace std;
set<string> text;
string temp,temp2;;
int main(){
    while(cin>>temp){
        for(int i=0;i<temp.length();++i){
            if(isalpha(temp[i])) temp[i]=tolower(temp[i]);
            else temp[i]=' ';
        }
        stringstream ss(temp);
        while(ss>>temp2){
            text.insert(temp2);
        }
    }
    for(auto i:text){
        cout<<i<<endl;
    }
    return 0;
}