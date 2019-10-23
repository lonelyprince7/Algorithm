#include<iostream>
using namespace std;
class Complex{
private:
    double real;
    double image;
public:
    Complex(double a=0,double b=0):real(a),image(b) {};
    friend Complex& operator++(Complex& rhs);
    friend Complex operator++(Complex& lhs,int);
    void display(){
        cout<<real<<endl;
        cout<<image<<endl;
    }
};
 Complex& operator++( Complex& rhs){
     rhs.image++;
     rhs.real++;
     return rhs;
 }
 Complex operator++( Complex& lhs,int){
     Complex old=lhs;
     lhs.real++;
     lhs.image++;
     return old;
 }
int main(){
    Complex c1(1,1);
    Complex c3=c1++;
    Complex c4=++c1;
    c3.display();
    c4.display();

    return 0;
}