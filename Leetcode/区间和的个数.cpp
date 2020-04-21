#include<bits/stdc++.h> //本题考查线段树
using namespace std;
struct tree{
    vector<int> t;
    int n_node;
    int n_leave;
    bool flag=1;//标记是否是满二叉树
    tree(vector<int>& rhs){
        if(rhs.size()%2==1){
            rhs.push_back(0); //保证为完全二叉树
            flag=0;
        }
        n_leave=rhs.size();
        n_node=2*rhs.size()-1;
        t.resize(n_node+1); //为了标号从1开始,特地多留一个
        for(int i=1;i<=n_leave;++i){
            t[n_node-n_leave+i]=rhs[i-1];
        }
        for(int i=n_node-n_leave;i>=1;--i){
            t[i]=t[2*i+1]+t[2*i];
        }
    }
    int query(int lo,int hi){
        int left=n_node-n_leave+lo+1;
        int right=n_node-n_leave+hi+1; //换算成树中下标
        int sum=0;
        while(left<right){
            if(left%2==1){
                sum+=t[left++];
            } 
            if(right%2==0){
                sum+=t[right--];
            }
            left/=2;right/=2;
        }
        sum+=t[left];
        return sum;
    }
    int func(int lower,int upper){
      int res=0;
      int u=n_leave-1;
      if(flag==0) u--; 
      for(int s=0;s<=u;++s){
          for(int t=s;t<=u;++t){
              int sum=query(s,t);
              if(sum>=lower&&sum<=upper) res++;
          }
      }  
      return res;
    }
};
int main(){
    vector<int> nums{-2,0,0};
    tree t(nums);
    cout<<t.func(-2,2)<<endl;
    return 0;
}