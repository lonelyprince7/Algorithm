

// //最小生成树解法
// #include<iostream>
// #include<algorithm>
// using namespace std;
// int func[1000];
// int n,m;
// int a,b,c;
// int cnt;
// class edge{
// public:
//     int x;
//     int y;
//     int time;
//     edge(int a,int b,int c):x(a),y(b),time(c){}
//     bool operator<(const edge& other){
//         return  time<other.time;
//     }
// };
// edge edges[1000000];
// int get_root(int cur){
//     if(func[cur]==cur){
//         return cur;
//     }
//     else return get_root(func[cur]);
// }
// int kruscal(edge edges[]){
//     int edge_no_circle;
//     int time;
//     for(int i=0;i<m;++i){
//         if(get_root(edges[i].x)!=get_root(edges[i].y)){
//             func[get_root(edges[i].y)]=get_root(edges[i].x);   //想象一个虚拟根节点，只有一个节点的时候虚拟根节点是自己　
//             edge_no_circle++;
//         }
//         time = edges[i].time;
//         if(edge_no_circle==n-1)
//             return time;          
//     }
//     return -1;
// }
// int main(){
//     cin>>n>>m;
//     for(int i=0;i<m;++i){
//         cin>>a>>b>>c;
//         edge r(a,b,c);
//         edges[i]=r;
//     }
//     sort(edges,edges+m);

//     //初始化并查集;
//     for(int i=1;i<=n;++i){
//         func[i]=i;
//     }

//     int res=kruscal(edges);
//     cout<<res;
//     return 0;
// }


//普通并查集解法
#include<iostream>
#include<algorithm>
using namespace std;
int func[1000];
int n,m;
int a,b,c;
class road{
public:
    int x;
    int y;
    int time;
    road(int a,int b,int c):x(a),y(b),time(c){}
    bool operator<(const road& other){
        return  time<other.time;
    }
};
road roads[1000000];
int get_root(int cur){
    if(func[cur]==cur){
        return cur;
    }
    else return get_root(func[cur]);
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        road r(a,b,c);
        roads[i]=r;
    }
    sort(roads,roads+m);

    //初始化并查集;
    for(int i=1;i<=n;++i){
        func[i]=i;
    }
    int time;
    int cnt=0;  //记录合并次数，也就是无环边的条数
    bool flag=0;
    for(int i=0;i<m;++i){
        int x=roads[i].x;
        int y=roads[i].y;
        if(get_root(x)!=get_root(y)){
            func[get_root(y)]=get_root(x);
            cnt++;
        }
        time=roads[i].time;
        if(cnt==m-1){
            flag=1;
            break;
        };
    }
    if(flag) cout<<time<<endl;
    else cout<<"-1"<<endl;
    return 0;
}