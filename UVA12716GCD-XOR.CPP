#include<iostream>
using namespace std;
const int max_num=300005;
int res[300005];
int func(int n){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){          //必须保证i比j大
            if((i-j)==(i xor j)){ 
                res[i]++;
            }
        }
    }
    for(int i=2;i<=n;++i){
        res[i] +=res[i-1];
    }
}
int main(){
    func(max_num);
    int t;
    int n;
    cin>>t;
    for(int i=1;i<=t;++i){
        cin>>n;
        cout<<"Case "<<i<<": "<<res[n]<<endl;
    }
    return 0;
}