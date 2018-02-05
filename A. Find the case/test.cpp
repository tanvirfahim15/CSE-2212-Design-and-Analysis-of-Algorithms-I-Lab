#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cmath>
#include<map>
#include <utility>
#include <iomanip>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define sz 1000001
#define intmax 2147483647
#define inf 99999
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
typedef long long LL;
typedef unsigned long long ULL;
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
 //cout << fixed;
//cout << setprecision(2);

struct node{
    int nd,cost;
    node(){}
    node(int _nd,int _cost){
        nd=_nd;
        cost=_cost;
    }
    bool operator >(const node &a)const{
        return cost>a.cost;
    }
};

vector<node> g[sz];
priority_queue<node, vector<node>, greater<node> > q;
int d[sz],par[sz];
void dijkstra(int n,int source,int dest){

    for(int i=0;i<n;i++){
        d[i]=inf;
        par[i]=-1;
    }
    d[source]=0;
    q.push(node(source,0));
    while(!q.empty()){
        int u=q.top().nd;
        q.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].nd;
            int w=g[u][i].cost;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                par[v]=u;
                q.push(node(v,d[v]));
            }
            else if((d[v]==d[u]+w)&&u<par[v])par[v]=u;
        }
    }
    if(d[dest]<inf){
        int u=dest;
        vector<int> path;
        while(u!=source){
            path.push_back(u);
            u=par[u];
        }
        path.push_back(source);
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++){
            printf("%d\n",path[i]);
        }
    }
    else printf("not reachable");

}
int main()
{
    freopen ("input.txt","r",stdin);
    int n,m,u,v,i,w;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(node(v,w));
        g[u].push_back(node(u,w));
    }
    dijkstra(n,0,1);




    return 0;
}
