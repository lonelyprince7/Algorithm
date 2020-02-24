#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> nums;
int main(){
    int n;
    cin>>n;
    cin.get();
    vector<vector<string>> nums;
    string t1,t2;
    for(int i=0;i<n;++i){
        vector<string> t2;
        for(int j=0;j<2;++j){
            getline(cin,t1);
            t2.push_back(t1);
        }
        nums.push_back(t2);
    }
    for(int i=0;i<n;++i){
        string v=nums[i][0];string t=nums[i][1];
        string tmp="";
        vector<string> a1,a2;
        for(int i=0;i<v.length();++i){
            if(v[i]!=' ') tmp+=v[i];
            else{
                a1.push_back(tmp);
                tmp="";
            }
        }
        a1.push_back(tmp);
        tmp="";
        for(int i=0;i<t.length();++i){
            if(t[i]!=' ') tmp+=t[i];
            else{
                a2.push_back(tmp);
                tmp="";
            }
        }
        a2.push_back(tmp);
        int p1,p2,q1,q2,d,z,h;

        //裸算去的时间
        p1=((a1[0][0]*10+a1[0][1])*60+a1[0][3]*10+a1[0][4])*60+a1[0][6]*10+a1[0][7];
        p2=((a1[1][0]*10+a1[1][1])*60+a1[1][3]*10+a1[1][4])*60+a1[1][6]*10+a1[1][7];
        if(a1.size()==2) d=abs(p2-p1);
        else{
            if(a1[2][1]=='+') d=abs(p2+24*3600*(a1[2][2]-'0')-p1);
            else d=abs(p2-24*3600*(a1[2][2]-'0')-p1);
        }

        //裸算回的时间
        q1=((a2[0][0]*10+a2[0][1])*60+a2[0][3]*10+a2[0][4])*60+a2[0][6]*10+a2[0][7];
        q2=((a2[1][0]*10+a2[1][1])*60+a2[1][3]*10+a2[1][4])*60+a2[1][6]*10+a2[1][7];
        if(a2.size()==2) z=abs(q2-q1);
        else{
            if(a2[2][1]=='+') z=abs(q2+24*3600*(a2[2][2]-'0')-q1);
            else  z=abs(q2-24*3600*(a2[2][2]-'0')-q1);
        }
        if(d==z) h=d;
        else h=(d+z)/2;

        int hour=h/3600;int minute=(h-hour*3600)/60;int second=h-hour*3600-minute*60;
        if(hour<10) cout<<"0"<<hour; else cout<<hour;cout<<":";
        if(minute<10) cout<<"0"<<minute;else cout<<minute;cout<<":";
        if(second<10) cout<<"0"<<second<<endl;else cout<<second<<endl;
    }
    return 0;
}