#include<iostream>
using namespace std;
int main(){
    string P="zhyzhy";
    string T="zhhahzhyzhyzzhyzz";
    int m=P.length();
    int n=T.length();

    int *pi=new int[m];
    pi[0]=0;
    int k=0;
    for(int q=2;q<=m;++q){
        while(k>0&&P[k]!=P[q-1])
            k=pi[k-1];
        if(P[k]==P[q-1]) k++;
        pi[q-1]=k;
    }

    int q=0;
    for(int i=1;i<=n;++i){
        while(q>0&&P[q]!=T[i-1]) q=pi[q-1];
        if(P[q]==T[i-1]) q++;
        if(q==m){
            cout<<i-m<<endl;
            q=pi[q-1];
        }
    }

    return 0;
}