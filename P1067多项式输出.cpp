#include<iostream>
#include<vector>
using namespace std;
vector<int> a;
int tmp,n;
int main(){
    cin>>n;
    a.reserve(n+1);
    for(int i=0;i<n+1;++i){
        cin>>tmp;
        a.push_back(tmp);
    }
    if(a.size()==1){
        cout<<a[0]<<endl;
        return 0;
    }
    if(n==1){
        if(a[0]==1) cout<<"x";
        else cout<<a[0]<<"x";
    }
    else{
        if(a[0]==1) cout<<"x^"<<n;
        else if(a[0]==-1) cout<<"-x^"<<n;
        else cout<<a[0]<<"x^"<<n;
    }
    for(int i=1;i<=n-1;++i){
        if(a[i]==1){
            if(n-i>1) cout<<"+"<<"x^"<<n-i;
            else cout<<"+"<<"x";
        }
        else if(a[i]==-1){
            if(n-i>1)cout<<"-"<<"x^"<<n-i;
            else cout<<"-"<<"x";
        }
        else{
            if(a[i]>0){
                if(n-i>1)cout<<"+"<<a[i]<<"x^"<<n-i;
                else cout<<"+"<<a[i]<<"x";
            }
            else if(a[i]==0) continue;
            else{
                if(n-i>1) cout<<a[i]<<"x^"<<n-i;
                else cout<<a[i]<<"x";
            }
        }
    } 
    if(a[n]==0){;}
    else if(a[n]>0) cout<<"+"<<a[n];
    else cout<<a[n];
    cout<<endl;
    return 0;
}