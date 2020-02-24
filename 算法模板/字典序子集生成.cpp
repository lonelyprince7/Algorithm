#include<iostream>
#include<vector>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> a{1,2,3,4,5,6};
    int max_elem = *max_element(a.begin(),a.end());
    vector<int> comb{1,2,5,6};
    int size=comb.size();
    int i;
    for(i=size-1;i>=0;i--){
            if(comb[i]<=max_elem-(size-i)){
                break;
            }
    }
    int base=comb[i];
    for(int j=i;j<=size-1;j++){
        comb[j]=++base;
    }
    cout<<"安字典序生成的下一个组合为:"<<endl;
    for(int i=0;i<=size-1;++i){
        cout<<comb[i]<<" ";
    }
    cout<<endl;
    return 0;
}