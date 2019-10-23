// #include<iostream>
// #include<vector>
// using namespace std;  //邻接表不加优先队列　
// int N,M,S;
// struct ListNode{
//     int vertex;
//     int weight;
//     ListNode(int v,int w):vertex(v),weight(w){}
// };
// vector<ListNode> e[10005];
// int dist[10005];
// int inf=2147483647;
// bool visit[10005];
// void Dijkstra(){
//     for(int i=1;i<=N;++i){
//         if(i==S) dist[i]=0;
//         else dist[i]=inf;
//     }
//     for(int i=1;i<=N;++i){
//         visit[i]=false;
//     }
//     visit[S]=true;
//     int n=N;
//     int j=S;
//     while(n--){
//         int min_dist=inf;
//         for(int i=1;i<=N;++i){
//             if(dist[i]<min_dist&&visit[i]==false) {
//                 min_dist=dist[i];
//                 j=i;
//             }
//         }
//         visit[j]=true;
//         for(auto node:e[j]){
//             if(node.weight+dist[j]<dist[node.vertex]){
//                 dist[node.vertex]=node.weight+dist[j];
//             }
//         }
//     }
//     for(int i=1;i<=N;++i){
//         cout<<dist[i]<<" ";
//     }
// }
// int main(){
//     cin>>N>>M>>S;
//     int u,v,w;
//     for(int i=0;i<M;++i){
//         cin>>u>>v>>w;
//         ListNode node(v,w);
//         e[u].push_back(node);
//     }
//     Dijkstra();
//     return 0;
// }








#include<iostream>
#include<vector>
#include<queue>
using namespace std;  //邻接表加优先队列优化
int N,M,S;
struct ListNode{
    int vertex;
    int weight;
    ListNode(int v,int w):vertex(v),weight(w){}
};
vector<ListNode> e[10005];
int dist[10005];
int inf=2147483647;
bool visit[10005];
struct cmp{
    bool operator()(vertex a,vertex b){
        return a.dist>b.dist;
    }
};
struct vertex{
    int id;
    int dist;
    vertex(int a,int b):id(a),dist(b){}
};
void Dijkstra(){
    priority_queue<vertex,cmp> q;
    for(int i=1;i<=N;++i){
        if(i==S) dist[i]=0;
        else dist[i]=inf;
        vertex v(i,dist[i]);
        q.push(v);
    }
    for(int i=1;i<=N;++i){
        visit[i]=false;
    }
    visit[S]=true;
    int n=N;
    int j=S;
    while(n--){
        int j=q.top().id;
        visit[j]=true;
        for(auto node:e[j]){
            if(node.weight+dist[j]<dist[node.vertex]){
                dist[node.vertex]=node.weight+dist[j];
            }
            vertex v(node.vertex,dist[node.vertex]);
            q.push(v);
        }
    }
    for(int i=1;i<=N;++i){
        cout<<dist[i]<<" ";
    }
}
int main(){
    cin>>N>>M>>S;
    int u,v,w;
    for(int i=0;i<M;++i){
        cin>>u>>v>>w;
        ListNode node(v,w);
        e[u].push_back(node);
    }
    Dijkstra();
    return 0;
}