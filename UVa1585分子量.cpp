#include<iostream>
#include<map>
using namespace std;
int main(){
    string s;
    map<char,float> m={{'C',12.01},{'H',1.008},{'O',16.00},{'N',14.01}};
    cin>>s;
    float sum=0;
    for(int i=0;i<s.length();++i){
        if(isalpha(s[i])){
            float subSum=0;
            while(isalpha(s[i])){
                subSum += m[s[i]];
                i++;
            }
            if(i!=s.length()){
                sum += subSum*(s[i]-'0');
            }
            else{
                sum+=subSum;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}