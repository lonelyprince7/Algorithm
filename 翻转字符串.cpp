#include<iostream>
#include<string>
using namespace std;
class B  {
private:
    int b;
public:
	B(int x)  {  b=x;}
	void setB(int x){ b = x; }
    void showB(){  cout<<"b="<<b<<endl;  }
};
class A  {
private:
    int a;
public:
	A(int x)  {  a=x; }
	void setA(int x){ a = x; }
    void showA(){  cout<<"a="<<a<<endl;  }
};

class C:public B, private A   //公有继承A，私有继承B
{
private:
   int c;
public:
	C(int a,int b,int c1):B(b),A(a) //派生类构造函数初始化
	{    
         c=c1;   }
	void setC(int x,int y)  {
		c = x;
		setB(y);  //通过B类的成员函数setB()为B类的私有成员b赋值
	}
	void showC()  {  cout<<"c="<<c<<endl;  }
	void showABC()  {
		showA();    //能否改成  cout<<"a="<<a<<endl;
		showB();    //能否改成  cout<<"b="<<b<<endl;   
		cout<<"c="<<c<<endl;
	}
};
int main()  {
C obj(1,2,3);
    cout<<"显示a,b,c"<<endl;
    obj.showABC();
	//cout<<"显示a"<<endl;
	// obj.showA();             
	// cout<<"显示b"<<endl;
	// obj.showB();            
    return 0;
}