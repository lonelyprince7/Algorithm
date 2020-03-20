#include<bits/stdc++.h>
using namespace std; //本题为动态规划
class Point{
public:
    int x;
    int y;
    int v;
    Point(int a,int b,int c):x(a),y(b),v(c){}
    bool operator<(const Point& rhs){
        return (this->v)<(rhs.v);
    }
};
int main(){
    vector<vector<int>> matrix{{9,9,4},{6,6,8},{2,1,1}};
    if(matrix.size()==0) return 0;
    int height=matrix.size();
    int width=matrix[0].size();
    vector<Point> points;
    points.reserve(height*width);
    for(int i=0;i<height;++i){
        for(int j=0;j<width;++j){
            points.push_back(Point(i,j,matrix[i][j]));
        }
    }
    sort(points.begin(),points.end());
    vector<vector<int>> dp(height,vector<int>(width,1));
    int res=1;
    for(Point p:points){
        if((p.y+1<=width-1)&&(matrix[p.x][p.y+1]<matrix[p.x][p.y])) dp[p.x][p.y] =max(dp[p.x][p.y],dp[p.x][p.y+1]+1);
        if((p.x+1<=height-1)&&matrix[p.x+1][p.y]<matrix[p.x][p.y]) dp[p.x][p.y] =max(dp[p.x][p.y],dp[p.x+1][p.y]+1);
        if((p.x-1>=0)&&matrix[p.x-1][p.y]<matrix[p.x][p.y]) dp[p.x][p.y] =max(dp[p.x][p.y],dp[p.x-1][p.y]+1);
        if((p.y-1>=0)&&matrix[p.x][p.y-1]<matrix[p.x][p.y]) dp[p.x][p.y] =max(dp[p.x][p.y],dp[p.x][p.y-1]+1);
        res=max(res,dp[p.x][p.y]);
    }
    cout<<res<<endl;;
    return 0;
};