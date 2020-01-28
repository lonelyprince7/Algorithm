#include<iostream>
using namespace std;
int main(){
    for(int a=1;a<=9;++a){ //三
        for(int b=0;b<=9;++b){ //羊
            for(int c=0;c<=9;++c){ //献
                for(int d=0;d<=9;++d){ //瑞
                    for(int e=1;e<=9;++e){ //祥
                        for(int f=0;f<=9;++f){ //生
                            for(int g=0;g<=9;++g){ //辉
                                for(int h=0;h<=9;++h){ //气
                                    int ca1=(d+g)/10;
                                    int ca2=(f+c+ca1)/10;
                                    int ca3=(d+b+ca2)/10;
                                    int ca4=(a+e+ca3)/10;
                                    if(((g+d)%10==h)&&((f+c+ca1)%10==d)&&((d+b+ca2)%10==f)&&((e+a+ca3)%10==b)&&\
                                    (ca4==a)){
                                        //10859672
                                        cout<<a<<b<<c<<d<<e<<f<<g<<h<<endl;
                                    }
                                }
                                
                             }
                        }
                     }
                }
            }
        }
    }
    return 0;
}