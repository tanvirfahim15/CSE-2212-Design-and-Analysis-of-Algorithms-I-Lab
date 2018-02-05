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
#define sz 1000001
#define intmax 2147483647
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
typedef long long LL;
typedef unsigned long long ULL;
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
//cout << fixed;
//cout << setprecision(2);
int s[sz];
void gflush()
{
    loop(sz)
    {
        s[i]=i;
    }
}

struct node
{
    int u,v,w;
    node() {}
    node(int _u,int _v,int _w)
    {
        u=_u;v=_v;w=_w;
    }
    bool operator >(const node &a)const
    {
        return w > a.w;
    }
};
int findset(int x){
    if(s[x]==x)
    return x;
    else{
        int y=findset(s[x]);
        s[x]=y;
        return y;
    }
}
void changeset(int x,int y)
{
    s[x]=y;
}
vector<node> graph;
priority_queue<node, vector<node>, greater<node> > pq;
int main()
{
    //freopen ("input.txt","r",stdin);
    gflush();
    int n,m;
    cin>>n>>m;
    loop(m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        pq.push(node(x,y,w));
       // cout<<x<<" "<<y<<" "<<w<<endl;
    }
    //cout<<endl;
    while(!pq.empty())
    {
        node cur=pq.top();

        pq.pop();

        if(findset(cur.u)!=findset(cur.v))
        {
           // cout<<cur.u<<" "<<cur.v<<" "<<cur.w<<endl;
            changeset(cur.u,cur.v);
            graph.push_back(cur);
        }
    }
    int ans=0;
    loop(graph.size())
    {
        ans+=graph[i].w;
    }
    cout<<ans<<endl;


    return 0;
}
