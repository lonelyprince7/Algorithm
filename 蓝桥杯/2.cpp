//本题用动态规划解决
#include<bits/stdc++.h>
using namespace std;
struct e{
    int row;
    int col;
    int flag;
    e(int a,int b,int c):row(a),col(b),flag(c){}
};
int res;
//1,2,3车，像，后
int nums[10][10],n,t1,t2;
vector<e> s;
char c;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>c>>t1>>t2;
        if(c=='Q'){
            nums[t1][t2]=3;
            s.push_back(e(t1,t2,3));
        }
        if(c=='R'){
            nums[t1][t2]=1;
            s.push_back(e(t1,t2,1));
        }
        if(c=='B'){
            nums[t1][t2]=2;
            s.push_back(e(t1,t2,2));
        }
    }
    bool totalsig=0;
    for(auto elem:s){
        int row=elem.row;
        int col=elem.col;
        int flag=elem.flag;
        bool sig=0;
        if(flag==1){
            for(int rrow=1;rrow<=8;++rrow){
                if(rrow!=row&&nums[rrow][col]) sig=1;
            }
            for(int ccol=1;ccol<=8;++ccol){
                if(ccol!=col&&nums[row][ccol]) sig=1;
            }
        }
        if(flag==2){
            for(int rrow=row-1,ccol=col-1;rrow>=1&&ccol>=1;--rrow,--ccol){
                if(nums[rrow][ccol]) sig=1;
            }
            for(int rrow=row+1,ccol=col+1;rrow<=8&&ccol<=8;++rrow,++ccol){
                if(nums[rrow][ccol]) sig=1;
            }
        }
        if(flag==3){
            for(int rrow=1;rrow<=8;++rrow){
                if(rrow!=row&&nums[rrow][col]) sig=1;
            }
            for(int ccol=1;ccol<=8;++ccol){
                if(ccol!=col&&nums[row][ccol]) sig=1;
            }
            for(int rrow=row-1,ccol=col-1;rrow>=1&&ccol>=1;--rrow,--ccol){
                if(nums[rrow][ccol]) sig=1;
            }
            for(int rrow=row+1,ccol=col+1;rrow<=8&&ccol<=8;++rrow,++ccol){
                if(nums[rrow][ccol]) sig=1;
            }
        }
        if(sig==1){
            totalsig=1;break;
        }
    }
    if(totalsig==1) cout<<"Attack!"<<endl;
    else cout<<"Safe!"<<endl;
    return 0;
}