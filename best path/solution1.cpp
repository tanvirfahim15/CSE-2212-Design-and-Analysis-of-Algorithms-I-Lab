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
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
typedef long long LL;
typedef unsigned long long ULL;
 //cout << fixed;
//cout << setprecision(2);
//priority_queue<node, vector<node>, greater<node> > q;
/*
struct point{
    int x,y;
    point(int _x,int _y){
        x=_x;
        y=_y;
    }
};
struct Xgreater
{
    bool operator()( const point& lx, const point& rx ) const {
        return lx.x < rx.x;
    }
};

    priority_queue<point,vector<point> , Xgreater> pq;
*/
struct edge{
    int u,v,w;
    edge(int uu,int vv,int ww){
        u=uu,
        v=vv;
        w=ww;
    }
    void print(){
        cout<<u<<" "<<v<<" "<<w<<endl;
    }

};
struct Xgreater
{
    bool operator()( const edge& lx, const edge& rx ) const {
        return lx.w < rx.w;
    }
};
vector<edge> edges;
int p[sz];
int fin(int u){
    if(p[u]==u)return u;
    else{
        int ret=fin(p[u]);
        p[u]=ret;
        return ret;
    }
}
void unite(int u,int v){
    p[fin(u)]=fin(v);
}

int main()
{
   // freopen ("input.txt","r",stdin);
    loop(sz)p[i]=i;
    int n,m;
    cin>>n>>m;
    loop(m){
        int u,v,w;
        cin>>u>>v>>w;
        edges.pb(edge(u,v,w));
    }
    sort(edges.begin(),edges.end(),Xgreater());
    int ans=0;
    loop(edges.size()){
        if(fin(edges[i].u)!=fin(edges[i].v)){
            unite(edges[i].u,edges[i].v);
            ans=max(edges[i].w,ans);
        }
    }
    cout<<ans<<endl;

    return 0;
}
