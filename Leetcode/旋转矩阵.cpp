#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> matrix{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> res=matrix;
    if(matrix.size()==0) return 0;
    for(int i=0;i<matrix.size();++i){
        for(int j=0;j<matrix[0].size();++j){
            res[i][j]=\
            matrix[matrix.size()-1-j][i];
        }
    }
     for(int i=0;i<matrix.size();++i){
        for(int j=0;j<matrix[0].size();++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}