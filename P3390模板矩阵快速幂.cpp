#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
const int mod=pow(10,8);
Mat a;
Mat e;
ll n,k;
struct Mat{
 ll m[105][105];
 int rows,cols;
};
Mat Mul(Mat x,Mat y){
    Mat res;
    res.rows=x.rows;
    res.cols=y.cols;
    for(int i=1;i<=x.rows;++i){
            for(int j=1;j<=y.cols;++j){
                for(int k=1;k<=x.cols;++k){  //换成y.rows也可
                    res.m[i][j] =res.m[i][j]%mod+x.m[i][k]*y.m[k][j]%mod;  //随时保持取模状态，保持不越界
                }
            }
        }
    return res;
}
Mat pow(Mat a,ll k){
    Mat res=e;   //此处乃浅拷贝，不过只需返回单位矩阵ｅ(相当于自然数１)，无妨
    Mat base=a;
    while(k){
        if(k&1)
            res=Mul(res,base);
        base=Mul(base,base);
        k>>=1;
    }
    return res;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;++j){
            cin>>a.m[i][j];
        }
    }
    a.rows=a.cols=n;
    for(int i=1;i<=n;++i){
        e.m[i][i]=1;
    }
    e.rows=n;
    e.cols=n;
    Mat res=pow(a,k);
    for(int i=1;i<=res.rows;i++){
        for(int j=1;j<=res.cols;++j){
            cout<<res.m[i][j]%mod<<" ";
        }
        cout<<endl;
    }
    return 0;
}
