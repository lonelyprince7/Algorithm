#include<bits/stdc++.h> //本题为大数相乘的典型例题
using namespace std;
int main(){
    string num1="123";
    string num2="456";
    if(num1.length()>num2.length()) swap(num1,num2);
    int l1=num1.length(),l2=num2.length(),tmp,carry=0;
    string pre="",next="",sum="";
    for(int i=l1-1;i>=0;--i){
        next="";tmp=carry=0;
        for(int j=l2-1;j>=0;--j){
            tmp=(num2[j]-'0')*(num1[i]-'0')+carry;
            carry=tmp/10;
            next.insert(0,1,tmp%10+'0');
        }
        if(carry!=0) next.insert(0,1,carry+'0');
        for(int k=l1-i-1;k>0;--k) next+='0';
        tmp=carry=0;
        if(pre=="") sum=next;
        else{
            sum="";
            for(int i=pre.size()-1;i>=0;--i){
                tmp=(next[i+1]-'0')+(pre[i]-'0')+carry;
                carry=tmp/10;
                sum.insert(0,1,(tmp%10)+'0');
            }
            if(next[0]-'0'+carry<10) sum.insert(0,1,(carry+(next[0]-'0'))+'0');
            else{
                sum.insert(0,1,(next[0]-'0'+carry)%10+'0');
                sum.insert(0,1,(next[0]-'0'+carry)/10+'0');
            }
        }
        pre=sum;
    }
    cout<<pre<<endl;
    return 0;
}