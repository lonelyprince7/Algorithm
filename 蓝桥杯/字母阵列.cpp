//本题考察矩阵坐标变换
#include<bits/stdc++.h>
#define N 8
using namespace std;
char nums[N+1][N+1];
int main(){
    ifstream in("/home/lonelyprince7/LocalCode/Algorithm/蓝桥杯/data3.txt");
    for(int i=1;i<=N;++i){
        string s;
        getline(in,s);
        for(int j=1;j<=N;++j){
            nums[i][j]=s[j-1];
        }
    }
    int res=0;
    // //左下->右上斜着匹配
    for(int s=7,t=7;s<=N;++s,++t){ //s:i坐标变化范围,t:j坐标变化范围
        string str="";
        for(int i=s,j=1;i>=1;--i,++j){
                str+=nums[i][j];
        }
        if(str.find("LANQIAO")!=std::string::npos) res++;
        reverse(str.begin(),str.end());
        if(str.find("LANQIAO")!=std::string::npos) res++;
    }
    for(int s=2,t=2;s<=N-6;++s,++t){
        string str="";
        for(int i=N,j=t;i>=s;--i,++j){
            str+=nums[i][j];
        }
        if(str.find("LANQIAO")!=std::string::npos) res++;
        reverse(str.begin(),str.end());
        if(str.find("LANQIAO")!=std::string::npos) res++;
    }

    // // //左上->右下斜着匹配
    for(int s=7,t=N-6;s<=N;++s,--t){
        string str="";
        for(int i=1,j=t;i<=s;++i,++j){
            str+=nums[i][j];
        }
        if(str.find("LANQIAO")!=std::string::npos) res++;
        reverse(str.begin(),str.end());
        if(str.find("LANQIAO")!=std::string::npos) res++;
    }
    for(int s=2,t=N-1;s<=N-6;++s,--t){
        string str="";
        for(int i=s,j=1;i<=N;++i,++j){
            str+=nums[i][j];
        }
        if(str.find("LANQIAO")!=std::string::npos) res++;
        reverse(str.begin(),str.end());
        if(str.find("LANQIAO")!=std::string::npos) res++;
    }


    // //水平匹配
    for(int i=1;i<=N;++i){
        string str="";
        for(int j=1;j<=N;++j){
            str+=nums[i][j];
        }
        if(str.find("LANQIAO")!=std::string::npos) res++;
        reverse(str.begin(),str.end());
        if(str.find("LANQIAO")!=std::string::npos) res++;
    }

    // // //垂直匹配
    for(int j=1;j<=N;++j){
        string str="";
        for(int i=1;i<=N;++i){
            str+=nums[i][j];
        }
        if(str.find("LANQIAO")!=std::string::npos) res++;
        reverse(str.begin(),str.end());
        if(str.find("LANQIAO")!=std::string::npos) res++;
    }

    cout<<res<<endl;
    return 0;
}