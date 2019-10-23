#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct block{
    int x,y,h;
    block(int a,int b,int c):x(a),y(b),h(c){}
    bool operator<(const block& rhs){
        return (x<rhs.x&&y<rhs.y);
    }
};  //定义一种砖头
vector<block> blocks;  //一共90种砖头
int f[180];  //以某种砖头做底部
int n;
int main(){
    blocks.reserve(90);
    int cnt=0;
    while(cin>>n){
        if(n==0) break;
        cnt++;
        blocks.clear();
        int a,b,c;
        for(int i=0;i<n;++i){
            cin>>a>>b>>c;
            block block1(a,b,c);
            block block2(c,b,a);
            block block3(c,a,b);
            block block4(b,a,c);
            block block5(b,c,a);
            block block6(a,c,b);
            blocks.push_back(block1);
            blocks.push_back(block2);
            blocks.push_back(block3);
            blocks.push_back(block4);
            blocks.push_back(block5);
            blocks.push_back(block6);
        }
        sort(blocks.begin(),blocks.end());
        f[0]=blocks[0].h;
        int res=f[0];
        for(int i=1;i<n;++i){
            f[i]=blocks[i].h;
            for(int j=i-1;j>=0;j--){
              if(blocks[j]<blocks[i]) f[i]=max(f[i],blocks[i].h+f[j]);
            }
            res=max(res,f[i]);
        }
        std::cout<<"Case "<<cnt<<": maximum height = "<<res<<endl;
    }
    return 0;
}