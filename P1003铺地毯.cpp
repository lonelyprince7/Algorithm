#include<iostream>
#include<vector>
using namespace std;
vector<vector<short>> map(200000,(vector<short>(200000,0)));
int main(){
    int n,a,b,g,k,x,y;
    cin>>n;
    for(int u=1;u<=n;++u){
        cin>>a>>b>>g>>k;
        for(int v=a;v<=a+g;++v)
            for(int w=b;w<=b+k;++w)
                map[v][w]=u;
    }
    cin>>x>>y;
    if(map[x][y]==0) cout<<"-1";
    else cout<<map[x][y]<<endl;
    return 0;
}