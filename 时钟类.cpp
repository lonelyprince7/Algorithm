#include<iostream>
using namespace std;
class Clock{
private:
    int iHour;
    int iMinute;
    int iSecond;
public:
    void showTime();
    void setTime(int hour=0,int minute=0,int second=0);
    Clock(int hour,int minute,int second);
    Clock();
    Clock(const Clock& clock);



};
int main(){
    Clock clock1;
    Clock clock2(1,1,1);
    // clock.setTime();
    clock1.showTime();                                 
    clock2.showTime();
    // clock.setTime(1,1,1);
    // clock.showTime();
    return 0;
}
void Clock::showTime(){ 
    cout<<"Hour is:"<<iHour<<",Minute is "<<iMinute<<",Second is"<<iSecond<<endl;
}
void Clock::setTime(int hour,int minute,int second){
    iHour = hour;
    iMinute=minute;
    iSecond=second;
}
Clock::Clock(int hour,int minute,int second){
    iHour=hour;
    iMinute=minute;  
    iSecond=second;
}
Clock::Clock(){
    iHour=0;
    iMinute=0;
    iSecond=0;
}
Clock::Clock(const Clock& other){
    (*this).iHour=other.iHour;
    this->iMinute=other.iMinute; 
}