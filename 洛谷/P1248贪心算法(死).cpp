#include<iostream>
#include<algorithm>
using namespace std;
struct product{
    int id;
    int t;
    bool k;
    product(){}
    product(int a,int b,int c):id(a),t(b),k(c) {}
    bool operator<(const product& other){
        return t<other.t;
    }
};
product a[2005];
int res[1005];
int main(){
    int n;
    int t;
    cin>>n;
    int i;
    for(i=0;i<n;++i){
        cin>>t;
        product p(i+1,t,1);
        a[i]=p;
    }
    for(;i<2*n;++i){
        cin>>t;
        product p(i+1-n,t,0);
        a[i]=p;
    }
    sort(a,a+2*n);
    int time;
    int cnt=0;
    int returnindex=-1;  //标记编号，等在a车间加工完了再回来在b加工
    for(int i=0;i<2*n;++i){
        if(a[i].k==1){
            res[cnt++]=a[i].id;
            time +=a[i].t;
            if(a[i].id<=n) a[i+n].k=true;
            if(returnindex==i+n)
           
        }
        else{
            if(returnindex==-1){
                returnindex=i;
                continue;
            }
            else{
                res[cnt++]=a[returnindex].id;
                if(a[returnindex].id<=n) a[returnindex+n].k=true;
                time+=a[returnindex].t;
            }
        }
    }
    cout<<time<<endl;
    for(int i=0;i<2*n;++i){
        cout<<res[i]<<endl;
    }
    return 0;
}