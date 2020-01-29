#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
bool isprime(int n){
    if(n<2) return 0;
    for(int i=2;i<=sqrt(n);++i){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
// bool isreverse(int n){
//     string str=to_string(n);
//     for(int i=0;i<=(str.length()-1)/2;++i){
//         if(str[i]!=str[str.length()-1-i]){
//             return 0;
//         }
//     }
//     return 1;
// }
// bool isreverse(int a)  //逆序翻转法
// {
//     int c=0,s=a;
//     while(a)
//     {
//         c=c*10+a%10;
//         a=a/10;
//     }
//     return c==s;
// }
vector<int> a;
int main(){
    int low,high;
    cin>>low>>high;
    // for(int i=low;i<=high;++i){
    //     if(isprime(i)&&isreverse(i)){
    //         cout<<i<<endl;
    //     }
    // }
    // return 0;
    int n;
    a.push_back(5);
    a.push_back(7);
    a.push_back(11);//2位数和1位数只有这三个是回文质数
    //3位回文数
    for(int d1=1;d1<=9;d1=+2){    // 只有奇数才会是素数
        for(int d2=0;d2<=9;d2++){
            n=100*d1+10*d2+d1;//(生成回文数...)
            a.push_back(n);
        }
    }
    //4位回文数
    for(int d1=1;d1<=9;d1=+2){    // 只有奇数才会是素数
        for(int d2=0;d2<=9;d2++){
            n=1000*d1+100*d2+10*d2+d1;//(生成回文数...)
            a.push_back(n);
        }
    }
    //5位回文数
     for(int d1=1;d1<=9;d1=+2){  
        for(int d2=0;d2<=9;d2++){
            for(int d3=0;d3<=9;d3++){          
                n=10000*d1+1000*d2+100*d3+10*d2+d1;
                a.push_back(n);
            }
        }
    }
    //6位回文数
     for(int d1=1;d1<=9;d1=+2){  
        for(int d2=0;d2<=9;d2++){
            for(int d3=0;d3<=9;d3++){          
                n=100000*d1+10000*d2+1000*d3+100*d3+10*d2+d1;
                a.push_back(n);
            }
        }
    }
    //7位回文数
    for(int d1=1;d1<=9;d1=+2){  
        for(int d2=0;d2<=9;d2++){
            for(int d3=0;d3<=9;d3++){
                for(int d4=0;d4<=9;d4++){
                    n=1000000*d1+100000*d2+10000*d3+1000*d4+100*d3+10*d2+d1;
                    a.push_back(n);
                }
            }
        }
    }
    //8位回文数
    for(int d1=1;d1<=9;d1=+2){  
        for(int d2=0;d2<=9;d2++){
            for(int d3=0;d3<=9;d3++){
                for(int d4=0;d4<=9;d4++){
                    n=10000000*d1+1000000*d2+100000*d3+10000*d4+1000*d4+100*d3+10*d2+d1;
                    a.push_back(n);
                }
            }
        }
    }
    for(int x:a){
        if(isprime(x)&&x>=low&&x<=high){
            cout<<x<<endl;
        }
    }
    return 0;
}