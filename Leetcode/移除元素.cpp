#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main(){
    vector<int> deck={1,1,1,1,1,2,2,2,2,2};
    if(deck.size()==0){
        cout<<"false"<<endl;
        return 0;
    }
    map<int,int> m;
    for(int i=0;i<deck.size();++i){
        m[deck[i]]++;
    }
    int val=m.begin()->second;
    bool flag=true;
    if(val<2) flag=false;
    for(auto iter=m.begin();iter!=m.end();++iter){
        if(iter->second<2){
            flag=false; break;
        }
        if(iter->second!=val){
            int gcdv=gcd(iter->second,val);
            if(gcdv>=2) val=gcdv;
            else{
                flag=false;break;
            }
        }
    }
    if(flag==true) cout<<"true"<<endl;
    else cout<<"false"<<endl;;
    return 0;
}