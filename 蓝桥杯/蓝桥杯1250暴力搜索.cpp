#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
struct sol{
    int a;
    int b;
    int c;
    sol(int x,int y,int z):a(x),b(y),c(z){}
    bool operator<(sol& rhs){
        if(this->a==rhs.a&&this->b==rhs.b) return this->c<rhs.c;
        else if(this->a==rhs.a) return this->b<rhs.b;
        else return this->a<rhs.a;
    }
};
int main(){
    int n;
    while(cin>>n){
        int flag=0;
        vector<sol> sols;
        for(int k=1;k<=sqrt(n);++k){
            for(int j=1;j<=k;++j){
                for(int i=1;i<=j;++i){
                    if(i*i+j*j+k*k==n){
                        flag=1;
                        sols.push_back(sol(i,j,k));
                    }
                }
            }
        }
        sort(sols.begin(),sols.end());
        for(auto i:sols) cout<<i.a<<" "<<i.b<<" "<<i.c<<endl;
        if(flag==0) cout<<"No Solution"<<endl;
    }
    return 0;
}