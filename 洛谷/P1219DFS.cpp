#include<iostream>
using namespace std;
int n,count,res[100],flag[3][100];
void dfs(int row){ 
    if(row>n&&count<=2){  //不是3是2
        for(int i=1;i<=n;++i)
            cout<<res[i]<<" ";
        cout<<endl;
        count++;
        return;
    }
    else if(row>n){
        count++;
        return;
    }
    else{
        for(int i=1;i<=n;++i){
            if((!flag[0][i])&&(!flag[1][row+i])&&(!flag[2][row-i+n])){
                res[row]=i;
                flag[0][i]=1;flag[1][row+i]=1;flag[2][row-i+n]=1;
                dfs(row+1);
                flag[0][i]=0;flag[1][row+i]=0;flag[2][row-i+n]=0;
            }
        }
    }
}
int main(){
    cin>>n;
    dfs(1);
    cout<<count<<endl;
    return 0;
}