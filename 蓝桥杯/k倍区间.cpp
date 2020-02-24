//本题使用前缀和
// 做法：首先统计前缀和sum[i] 表示A1+A2+…+Ai.
// 所以对于任意一段区间[l,r]的和就是sum[r]-sum[l-1].
// 如果要保证这个区间和为K倍数就是：(sum[r]-sum[l-1])%k == 0.
// 变形后就是：sum[r]%k==sum[l-1]%k，
// 所以我们计算前缀和的时候顺带模K，然后统计前缀和中相同的数据就行了。
// 复杂度O(n).注意数据可能会溢出！！
#include<bits/stdc++.h>
using namespace std;    
typedef long long ll;
ll nums[100005];
ll book[100005];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>nums[i];
    }
    nums[0]=0;
    ll sum=0;
   /* 前缀和取模后的序列：1 1 0 0 1
    第1个1，不能组合，第二个1，可与前面一个1组合，
    第3个0，不能组合，第4个0，可与前面1个0组合，第5个1，可与前面2个1组合*/
    for(int i=1;i<=n;++i){
        nums[i]=(nums[i-1]+nums[i])%k;
        sum+=book[nums[i]];
        book[nums[i]]++;
        if(nums[i]==0) sum++; //本身模0,无须组合
    }
    cout<<sum<<endl; 
    return 0;
}