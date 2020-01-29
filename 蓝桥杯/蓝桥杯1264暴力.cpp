#include<iostream>
using namespace std;
int main(){
    int cnt=0;
    for(int b=2;b<=10;++b){
        for(int c=b+1;c<=10;++c){
            for(int d=c+1;d<=10;++d){
                for(int e=d+1;e<=10;++e){
                    for(int f=a+1;f<=10;++f){
                        +g){
                            for(int h=c+1;h<=9;++h){
                                for(int i=d+1;i<=9;++i){
                                    if(b>a&&f>a&&c>b&&g>b&&\
                                    d>c&&h>c&&e>d&&i>d){
                                        if(b!=f&&c!=f&&c!=g&&d!=f&&d!=g&&d!=h&&\
                                        e!=f&&e!=g&&e!=h&&e!=i){
                                            cout<<a<<b<<c<<d<<e<<f<<g<<h<<i<<j<<endl;
                                            cnt++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}