#include<iostream>
using namespace std;
class base{
public:
    void template_method(){
        func();
    }
   virtual void func()=0;
};
class derived:public base{
    virtual void func(){
        cout<<"hello!"<<endl;
    }
};
int main(){
    derived j;
    j.template_method();
    return 0;
}