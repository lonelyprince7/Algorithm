//本题采用模拟方法即可解决
#include<bits/stdc++.h>
using namespace std;
struct Date{
    string year;
    string month;
    string day;
    Date(string a,string b,string c):year(a),month(b),day(c){}
    bool operator<(Date rhs){
        if(year!=rhs.year){
            return year<rhs.year;
        }
        else if(month!=rhs.month){
            return month<rhs.month;
        }
        else{
            return day<rhs.day;
        }
    }
};
bool isrun(int year){
    return (year%400==0)||((year%4==0)&&(year%100!=0));
}
vector<Date> res;vector<string> nums;
int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int y_days[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main(){
    string s,t="";
    cin>>s;
    for(int i=0;i<s.length();++i){
        if(s[i]!='/'){
            t+=s[i];
        }
        else{
            nums.push_back(t);
            t="";
        }
    }
    nums.push_back(t);
    //年月日情况
    if("00"<=nums[0]&&nums[0]<="59"&&"01"<=nums[1]&&nums[1]<="12"&&"01"<=nums[2]&&nums[2]<="31")
        res.push_back(Date("20"+nums[0],nums[1],nums[2]));
    else if("60"<=nums[0]&&nums[0]<="99"&&"01"<=nums[1]&&nums[1]<="12"&&"01"<=nums[2]&&nums[2]<="31")
        res.push_back(Date("19"+nums[0],nums[1],nums[2]));
    //月日年情况
    if("00"<=nums[2]&&nums[2]<="59"&&"01"<=nums[0]&&nums[0]<="12"&&"01"<=nums[1]&&nums[1]<="31")
        res.push_back(Date("20"+nums[2],nums[0],nums[1]));
    else if("60"<=nums[2]&&nums[2]<="99"&&"01"<=nums[0]&&nums[0]<="12"&&"01"<=nums[1]&&nums[1]<="31")
        res.push_back(Date("19"+nums[2],nums[0],nums[1]));
    //日月年情况
    if("00"<=nums[2]&&nums[2]<="59"&&"01"<=nums[1]&&nums[1]<="12"&&"01"<=nums[0]&&nums[0]<="31")
        res.push_back(Date("20"+nums[2],nums[1],nums[0]));
    else if("60"<=nums[2]&&nums[2]<="99"&&"01"<=nums[1]&&nums[1]<="12"&&"01"<=nums[0]&&nums[0]<="31")
        res.push_back(Date("19"+nums[2],nums[1],nums[0]));
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();++i){
        if(isrun(atoi(res[i].year.c_str()))&&(atoi(res[i].day.c_str())<=(y_days[atoi(res[i].month.c_str())])))
            cout<<res[i].year<<"-"<<res[i].month<<"-"<<res[i].day<<endl;
        else if(!isrun(atoi(res[i].year.c_str()))&&(atoi(res[i].day.c_str())<=(days[atoi(res[i].month.c_str())])))
            cout<<res[i].year<<"-"<<res[i].month<<"-"<<res[i].day<<endl;
    }
    return 0;
}