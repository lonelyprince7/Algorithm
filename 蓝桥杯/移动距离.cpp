//本题为常见的模拟题型
#include<bits/stdc++.h>
using namespace std;
int main(){
    int w,m,n;
    while(cin>>w>>m>>n){
        if(m>n) swap(m,n);
        int line1=(m-1)/w;
        int line2=(n-1)/w;
        int step=0;
        if(line1<line2){
            int offset=0;
            if(line2%2==1){
                offset=w-n%w;
            }
            else offset=(n-1)%w;
            if(line1%2==1) step+=abs((w-m%w)-offset);
            else step+=abs((m-1)%w-offset);
            step+=line2-line1;
        }
        else{
            step+=abs(m-n);
        }
        cout<<step<<endl;
    }
    return 0;
}