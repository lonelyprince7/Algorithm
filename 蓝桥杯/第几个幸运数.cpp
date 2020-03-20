#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Max = 59084709587505;
int a[3] = {3,5,7};
void Find(LL Max)
{
    set<LL> se;
    LL t  = 1;
    while(1)
    {
        for(int i = 0; i < 3; ++i)
        {
            LL tt = t*a[i];
            if(tt <= Max)
            se.insert(tt);
        }
        t = *se.upper_bound(t);//返回查找序列中第一个大于查找值的指针,因为不确定是*3,*5 or *7
        //注意,lower_bound返回的是被查序列中第一个大于等于查找值的指针
        if(t == Max)
            break;
    }
    for(set<LL>::iterator it = se.begin(); it != se.end(); ++it)
        cout<<*it<<endl;

    cout<<"answer = "<<se.size()<<endl;
}
int main(void)
{
    Find(Max);
    return 0;
}


