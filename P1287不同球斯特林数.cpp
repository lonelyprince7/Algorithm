//不同球不同盒子　递归做法
// #include<iostream>
// using namespace std;
// int fact(int n){
//     if(n==0) return 1;
//     else return n*fact(n-1);
// }
// //求n个不同球分成r堆的情况数
// int pile(int n,int r){  //１个盒子,１个球临界条件
//     if(n<r) return 0; //剪枝
//     if(n==r) return 1; //剪枝
//     if(n==0&&r==0) return 1;   //球和盒子都用完
//     if(n==0||r==0) return 0;   //球或盒子有剩 
//     return 1*pile(n-1,r-1)+pile(n-1,r)*r;   //第二个式子*ｒ容易漏！
// }
// int main(){
//     int n,r;
//     cin>>n>>r;
//     if(n<r){
//         cout<<"0"<<endl;
//         return 0;
//     }
//     if(n==r){
//         cout<<fact(n)<<endl;
//         return 0;
//     }
//     int res=pile(n,r)*fact(r);
//     cout<<res<<endl;
//     return 0;
// }


//不同球不同盒子　DP做法
#include<iostream>
#include<map>
using namespace std;
int f[100][100];
//求n个不同球分成r堆的情况数
int n,r;
int fact(int n){
    if(n==0) return 1;
    else return n*fact(n-1);
}
int main(){
    cin>>n>>r;
    f[0][0]=1;
    f[0][1]=0;
    f[1][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=min(i,r);++j){   //可以到r, 也可以min(i,r)
            f[i][j]=f[i-1][j-1]+f[i-1][j]*j;   //斯特林数，和杨辉三角的组合数递推相比，多乘以个j
        }
    }
    cout<<f[n][r]*fact(r)<<endl;
    return 0;
}