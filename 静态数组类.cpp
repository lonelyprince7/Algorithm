#include<iostream>
using namespace std;
class Array{
private:
    const static int MAX_SIZE=10;
    int a[MAX_SIZE];
public:
    Array(int k);//构造函数
    Array(const Array& other);  //拷贝构造函数
    Array& operator=(const Array& rhs); //拷贝赋值函数
    int operator[](size_t index) const; //重载[]运算符
    int& operator[](size_t index); //重载[]运算符
    bool operator==(const Array& rhs); //重载比较运算符
    int length() const{ return MAX_SIZE;} //返回数组长度
};

int main(){
    Array a1(3);
    Array a2(3);
    cout<<"a1如下:"<<endl;
    for(int i=0;i<a1.length();++i){
        cout<<a1[i]<<" ";
    }
    cout<<endl;
    cout<<"a2如下:"<<endl;
    for(int i=0;i<a2.length();++i){
        cout<<a2[i]<<" ";
    }
    cout<<endl;
    if(a1==a2) cout<<"a1 == a2!"<<endl;
    else cout<<"a1!=a2"<<endl;
    a2[0]=1;
    cout<<"a1如下:"<<endl;
    for(int i=0;i<a1.length();++i){
        cout<<a1[i]<<" ";
    }
    cout<<endl;
    cout<<"a2如下:"<<endl;
    for(int i=0;i<a2.length();++i){
        cout<<a2[i]<<" ";
    }
    cout<<endl;
    if(a1==a2) cout<<"a1 == a2!"<<endl;
    else cout<<"a1!=a2"<<endl;
    return 0;
}

Array::Array(int k=0){
    for(int i=0;i<MAX_SIZE;++i)
         a[i]=k;
}
Array::Array(const Array& other){
    for(int i=0;i<MAX_SIZE;++i)
        a[i]=other.a[i];
}
Array& Array::operator=(const Array& rhs){
    for(int i=0;i<MAX_SIZE;++i){
        a[i]=rhs.a[i];
    }
}
int Array::operator[](size_t index) const{
    return a[index];
}
int& Array::operator[](size_t index) {
    return a[index];
}
bool Array::operator==(const Array& rhs){
    for(int i=0;i<MAX_SIZE;++i){
        if(a[i]!=rhs.a[i]){
            return false;
        }
    }
    return true;
}