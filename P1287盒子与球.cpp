//斯特林数，动态规划




























// //递归解法
// #include<iostream>
// #include<algorithm>
// using namespace std;
// long func(int n,int r){
//     if(n<r) return 0;
//    // if(n<r) return 0;
//     if(r==0&&n==0) return 1;
//     //if(n==0||r==0||n<r) return 0;
//     else return func(n-1,r-1)+n*r*func(n-1,r);
// }
// int main(){
//     int r,n;
//     cin>>n>>r;
//     cout<<func(n,r)<<endl;
//     return 0;
// }#$
#include<iostream>
#include<vector>

using namespace std;
vector<int> a;
int tmp,n;
int main(){
    cin>>n;
    a.reserve(n+1);
    for(int i=0;i<n;++i){
        cin>>tmp;
        a.push_back(tmp);
    }
    if(a.size()==1){
        cout<<a[0]<<endl;
        return 0;
    }
    if(a[0]==0){;}
    else cout<<a[0]<<"x^"<<n;
    for(int i=1;i<n-1;++i){
        if(a[i]==1) cout<<"+"<<"x^"<<n-i;
        else if(a[i]==-1) cout<<"-"<<"x^"<<n-i;
        else{
            if(a[i]>0) cout<<"+"<<a[i]<<"x^"<<n-i;
            else if(a[i]==0) continue;
            else cout<<a[i]<<"x^"<<n-i;
        }
    }
    
    if(a[n]==0){;}
    else if(a[n]>0) cout<<"+"<<a[n];
    else cout<<a[n];
    cout<<endl;
    return 0;
}