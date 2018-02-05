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
struct edge
{
    int u,v,w;
    edge(int uu,int vv,int ww)
    {
        u=uu,
        v=vv;
        w=ww;
    }
    void print()
    {
        cout<<u<<" "<<v<<" "<<w<<endl;
    }

};
struct Xgreater
{
    bool operator()( const edge& lx, const edge& rx ) const
    {
        return lx.w < rx.w;
    }
};
int p[sz],r[sz];
int fin(int u)
{
    if(p[u]==u)
        return u;
    else
    {
        int ret=fin(p[u]);
        p[u]=ret;
        return ret;
    }
}
void unite(int u,int v)
{
    int x=fin(u);
    int y=fin(v);
    if(r[x]>r[y])
    {
        p[y]=x;
        r[y]+=r[x];
    }
    else{

        p[x]=y;
        r[x]+=r[y];
    }
}
int mst(vector<edge> edges,int n)
{

    loop(sz)
    {
        p[i]=i;
        r[i]=1;
    }
    sort(edges.begin(),edges.end(),Xgreater());
    int ans=0;
    loop(edges.size())
    {
        if(fin(edges[i].u)!=fin(edges[i].v))
        {
            unite(edges[i].u,edges[i].v);
            ans+=edges[i].w;
        }
    }
    int pr=fin(0);
    loop(n)
    {
        if(fin(i)!=pr)
            return intmax;
    }
    return ans;
}
vector<edge>  vmst(vector<edge> edges)
{
    vector<edge> ret;
    loop(sz)
    {
        p[i]=i;
        r[i]=1;
    }
    sort(edges.begin(),edges.end(),Xgreater());
    int ans=0;
    loop(edges.size())
    {
        if(fin(edges[i].u)!=fin(edges[i].v))
        {
            unite(edges[i].u,edges[i].v);
            ret.pb(edges[i]);
        }
    }
    return ret;
}
int main()
{
    //freopen ("input.txt","r",stdin);

    vector<edge> edges,mstedges;
    int n,m;
    cin>>n>>m;
    loop(m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.pb(edge(u,v,w));
    }
    mstedges=vmst(edges);
    int ans=intmax;
    loop(mstedges.size())
    {
        vector<edge> param;
        loopj(edges.size())
        {
            if(edges[j].u==mstedges[i].u&&edges[j].v==mstedges[i].v)
                continue;
            param.pb(edges[j]);
        }
        ans=min(ans,mst(param,n));
    }
    if(ans==intmax)
        cout<<"No Second Best MST"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
