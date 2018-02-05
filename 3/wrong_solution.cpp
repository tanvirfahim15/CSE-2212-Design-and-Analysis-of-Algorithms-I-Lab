#include<bits/stdc++.h>
using namespace std;

#define inf (1<<29)
#define ii64 long long
#define MX 100002

struct node{
    int nd, cost;
    node(){}
    node(int _nd,int _cost){
        nd = _nd;
        cost = _cost;
    }
    bool operator >(const node &a)const{
        return cost > a.cost;
    }
};

vector<node> g[MX];
int d[MX];

int dijkstra(int n,int source,int dest){
    priority_queue<node, vector<node>, greater<node> > q;
    for(int i = 0; i < n; i++){
        d[i] = inf;
    }
    while(!q.empty())q.pop();
    d[source] = 0;
    q.push(node(source,0));
    while(!q.empty()){
        int u = q.top().nd;
        q.pop();
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i].nd;
            int w = g[u][i].cost;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push(node(v,d[v]));
            }
        }
    }
    return d[dest];
}

int bfs(int n,int source,int dest){
    queue<node> q;
    for(int i = 0; i < n; i++){
        d[i] = inf;
    }
    while(!q.empty())q.pop();
    d[source] = 0;
    q.push(node(source,0));
    while(!q.empty()){
        int u = q.front().nd;
        q.pop();
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i].nd;
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                q.push(node(v,d[v]));
            }
        }
    }
    return d[dest];
}


int main(){
    int n,m,u,v,w,offset,res;
    scanf("%d %d",&n, &m);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(node(v,w));
        g[v].push_back(node(u,w));
    }
    scanf("%d",&offset);
    res = dijkstra(n,0,1) - bfs(n,0,1)*offset;
    printf("%d\n",res);
    return 0;
}

