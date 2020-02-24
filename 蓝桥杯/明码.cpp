//本题考察补码反码转换
#include<bits/stdc++.h>
using namespace std;
string to_bin(int a){
    if(a>0){
        string tmp="";
        while(a){
            tmp+=(a%2+'0');
            a/=2;
        }
        reverse(tmp.begin(),tmp.end());
        while(tmp.length()<8)
            tmp.insert(tmp.begin(),'0'); //一定要记住高位补0
        return tmp;
    }
    else if(a<0){
        string tmp="";
        a+=256;
        while(a){
            tmp+=(a%2+'0');
            a/=2;
        }
        reverse(tmp.begin(),tmp.end());
        return tmp;
    }
    else{
        return "00000000";
    }
}
int main(){
    ifstream in;
    in.open("/home/lonelyprince7/LocalCode/Algorithm/蓝桥杯/data.txt");
    if(!in) cout<<"error"<<endl;
    int tmp;
    string s;
    while(in>>tmp){
        s+=to_bin(tmp);
        for(int i=1;i<=31;++i){
            in>>tmp;
            s+=to_bin(tmp);
        }
    }
    for(int i=0;i<10;++i){
        for(int j=0;j<16;++j){
            for(int k=0;k<16;++k){
                cout<<s[i*256+16*j+k];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    printf("%ld",pow(9,9));
    return 0;
}