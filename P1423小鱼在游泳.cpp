#include<iostream>
using namespace std;
int main(){
    double dst;
    cin>>dst;
    double cur=0;
    int n=1;
    double step=2.0;
    cur +=step;
    while(cur<dst){
        n++;
        step *=0.98;
        cur += step;
    }
    cout<<n<<endl;
    return 0;
}