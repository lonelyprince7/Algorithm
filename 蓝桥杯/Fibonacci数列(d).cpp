//本题考查Fiboccani闭公式,但double位数不够放不下
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double fn=(pow((1+sqrt(5))/2,n)-pow((1-sqrt(5))/2,n))/sqrt(5);
    double ffn=(pow((1+sqrt(5))/2,n+1)-pow((1-sqrt(5))/2,n+1))/sqrt(5);
    cout<<fn<<" "<<ffn<<endl;
    printf("%.8f \n",fn/ffn);
    return 0;
}