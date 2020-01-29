// #include<iostream>   
// using namespace std;
// int V;
// int w[35];
// int n;
// int f[20005];  //总容量为j时，不装i物体，所能占的最大体积
// int main(){
//     cin>>V;
//     cin>>n;
//     for(int i=0;i<n;++i){
//         cin>>w[i];
//     }
//     for(int i=0;i<=n;++i){
//         for(int j=V;j>=w[i];j--){
//             f[j]=max(f[j],f[j-w[i]]+w[i]);
//         }
//     }
//     cout<<V-f[V]<<endl;
//     return 0;
// }   //优化为一位数组的０，１背包问题

#include<iostream>   
#include<cstring>
using namespace std;
int V;
int w[35];
int n;
int f[35][20005];  //当可以选第i个元素之前的元素(i可以要可以不要),可用空间为j时,最多能装多少
int main(){
    cin>>V;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>w[i];
    }
    memset(f,0,sizeof(0));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=V;++j)
            if(w[i]>j) f[i][j]=f[i-1][j];  //避免后面越界　
            else f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+w[i]);   //不管你要是不要，都要表示成为子问题,都要有i-1
    cout<<V-f[n][V]<<endl;
    return 0;
}  