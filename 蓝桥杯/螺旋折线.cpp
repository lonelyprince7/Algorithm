//本题考查分类讨论思想
#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    if(x==0&&y==0){
        cout<<0<<endl;return 0; //特判(0,0)
    }
    int width;
    //特判第一圈x轴上横着的部分 
    if(y==0&&x<0&&x>=-1) width=1;
    else if(x<0&&y<0&&abs(x)<=abs(y)+1){ //第三象限横着的部分,左开右闭
        width=abs(y)+1;
    }
    else{
        width=max(abs(x),abs(y));//其余部分
    }
    long long total_length=4*width*width;
    cout<<"total_length:"<<endl;
    total_length += 3*width;//等差数列求和通项公式
    long long cnt=0;
    //下面计算该点离该圈终点有多远
    if(y==-(width-1)&&x<0&&x>=-width){
        cnt+=width-(-x); //走完第三象限横着的部分,左开右闭
        cnt+=(width-1)+6*width;  //走完其余部分
    }
    else if((x==-width)&&y<=0&&y>-(width-1)){ //第三象限竖着的部分
        cnt+=-y;//走完第三象限竖着的部分
        cnt+=6*width; //走完其余部分
    }
    else if(x==-width&&y>0&&y<=width){ //第二象限竖着部分
        cnt+=width-y;
        cnt+=5*width;
    }
    else if((y==width)&&(x>-width)&&x<=0){ //二象限横着部分
        cnt+=-x;
        cnt+=4*width;
    }
    else if(y==width&&x>0&&x<=width){//一象限横着部分
        cnt+=width-x;
        cnt+=3*width;
    }
    else if(x==width&&y<width&&y>=0){ //一象限竖着部分
        cnt+=y;
        cnt+=2*width;
    }
    else if(x==width&&y<0&&y>=-width){//四象限竖着部分
        cnt+=width-(-y);
        cnt+=width;
    }
    else if(y==-width&&x<width&&x>=0){//三象限横着部分
        cnt+=x;
    }
    cout<<total_length-cnt<<endl; //差值即为该点的总距离
    return 0;
}