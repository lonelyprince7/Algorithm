#include<iostream>
#include<algorithm>
using namespace std;
class farmer{
public:
    int Pi;
    int Ai;
    farmer(){}  //给一个默认构造函数，申请内存的时候用
    farmer(int x,int y):Pi(x),Ai(y){}
    bool operator<(const farmer& other){
        return Pi<other.Pi;
    }
};
farmer a[5005];
int main(){
    int N,M,x,y;
    cin>>N>>M;
    for(int i=0;i<M;++i){
        cin>>x>>y;
        farmer f(x,y);
        a[i]=f;
    }
    sort(a,a+M);
    int i=0;
    int price=0;
    while(N-a[i].Ai>0){
        N -= a[i].Ai;
        price += a[i].Ai*a[i].Pi;
        i++;
    }
    price += N*a[i].Pi;
    cout<<price<<endl;
    return 0;
}