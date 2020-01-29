#include<iostream>
using namespace std;
long long quick_power(long long b,long long p,long long k){
    long long ans =1;
    long long base=b;  //最后一位b^(2^0)要要
    while(p){  //ｐ为0截止移位　
        if(p&1){ //必须要p对应的二进制位不为０才可以乘,如p=11,有１　２　８　，缺４
            ans*=base; //比如b^11=b^1*b^2*b^8 base就是指b^1,b^2,b^4,b^8
            ans %=k;
        }
         base *=base; //(base 表示b的某二进制位对应的次方) b^(2^0)->b^(2^1)->b^(2^2)都是b自乘结果
         //不管按照p的标准乘不乘那个base,base总是要按位上升的
        base %=k;
        p >>=1;
    }
    return ans%k;
}
int main(){
    long long b,p,k;
    cin>>b>>p>>k;
    cout<<b<<"^"<<p<<" mod "<<k<<"="<<quick_power(b,p,k)<<endl;
    return 0;
}