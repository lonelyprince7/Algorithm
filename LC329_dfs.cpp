// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<vector<int>> matrix{
//         {7,7,5},
//         {2,4,6},
//         {8,2,0}
//     };
//     int height=matrix.size();
//     int width=matrix[0].size();
//     vector<vector<int>> dp(height,vector<int>(width,1));
//     for(int k=1;k<=width*height;++k){
//         for(int i=0;i<height;++i){
//             for(int j=0;j<width;++j){
//                 if((j+1<width)&&matrix[i][j+1]>matrix[i][j]&&(dp[i][j+1]+1>dp[i][j])) dp[i][j] =dp[i][j+1]+1;
//                 if((i+1<height)&&matrix[i+1][j]>matrix[i][j]&&(dp[i+1][j]+1>dp[i][j])) dp[i][j] =dp[i+1][j]+1;
//                 if((i-1>=0)&&matrix[i-1][j]>matrix[i][j]&&(dp[i-1][j]+1>dp[i][j])) dp[i][j] =dp[i-1][j]+1;
//                 if((j-1>=0)&&matrix[i][j-1]>matrix[i][j]&&(dp[i][j-1]+1>dp[i][j])) dp[i][j] =dp[i][j-1]+1;
//             }
//         }
//     }
//     int res=1;
//     for(int i=0;i<height;++i){
//         for(int j=0;j<width;++j){
//             res=max(res,dp[i][j]);
//         }
//     }
//     cout<<res<<endl;
//     return 0;
// }



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

class Solution {
public: 
    int longestIncreasingPath(vector<vector<int>>& matrix){
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
        return res;
    }
};