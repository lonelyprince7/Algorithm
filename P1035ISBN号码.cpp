#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int count=0;
    int weight=1;
    for(char ch:s){
        if(weight==10){
            count %=11;
            break;
        }
        if(ch=='-') continue;
        else{
            count +=weight*(ch-'0');
            weight++;
        }
    }
    if(count==10&&*(s.end()-1)=='X'){
        cout<<"Right"<<endl;
        return 0;
    }
    else if(count==10&&*(s.end()-1)!='X'){
        *(s.end()-1)='X';
        cout<<s<<endl;
        return 0;
    }   
    else if(count!=10&&*(s.end()-1)==count+'0'){
        cout<<"Right"<<endl;
        return 0;
    }
    else if(count!=10&&*(s.end()-1)!=count+'0'){
        *(s.end()-1)=count+'0';
        cout<<s<<endl;
        return 0;
    }
    return 0;
}