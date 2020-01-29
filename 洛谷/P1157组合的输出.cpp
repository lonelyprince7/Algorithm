#include<iostream>
#include<iomanip>
using namespace std;
int n,r;
int tmp[30];
int index=1;
int main(){
    cin>>n>>r;
    while(index) //如果连index=1时都回退了那就变成０,退出循环
    {
        if(index>=r+1){
            for(int i=1;i<=r;++i){
                cout<<setw(3)<<tmp[i];
            }
            cout<<endl;
            index--;    //此处不能令其为0，非０标记在tmp内
            continue;
        }
        if(tmp[index]==0){
            tmp[index]=tmp[index-1]+1;
            index++;
            continue;

        }
        if(r-index<n-tmp[index]){
            tmp[index]++;
            index++;
            continue;
        }
        tmp[index]=0;  //退栈
        index--;
    }
    return 0;
}
//递归解法
// #include<iostream>
// #include<vector>
// #include<iomanip>
// using namespace std;
// vector<int> s;
// int n,r;
// void comb(int i){
//     if(n-i<r-s.size()) return; //剪枝
//     if(s.size()==r){
//         for(auto k:s)
//             cout<<setw(3)<<k;
//         cout<<endl;
//         return;
//     }
//     for(int j=i+1;j<=n;++j){
//         s.push_back(j);
//         comb(j);
//         s.pop_back();
//     }
// }
// int main(){
//     cin>>n>>r;
//     comb(0);
//     return 0;
// }
//所谓递归层数，即是r的值，可直接用存得的个数来控制递归！
// 难点，visit数组如何标记走过的路？