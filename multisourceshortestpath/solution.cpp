#include<bits/stdc++.h>
using namespace std;
#define inf (1<<29)
#define ii64 long long
#define MX 100002
struct node
{
    int nd, cost;
    node() {}
    node(int _nd,int _cost)
    {
        nd = _nd;
        cost = _cost;
    }
    bool operator >(const node &a)const
    {
        return cost > a.cost;
    }
};
vector<node> g[MX];
int d[MX];
void dijkstra(int n)
{
    for(int i = 0; i < n; i++)
    {
        d[i] = inf;
    }
    priority_queue<node, vector<node>, greater<node> > q;
    while(!q.empty())
        q.pop();
    int k;
    cin>>k;
    for(int i=0; i<k; i++)
    {
        int s;
        cin>>s;
        d[s]=0;
        q.push(node(s,0));
    }

    while(!q.empty())
    {
        int u = q.top().nd;
        q.pop();
        for(int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].nd;
            int w = g[u][i].cost;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push(node(v,d[v]));
            }
        }
    }
}

int main()
{
  //  freopen ("input.txt","r",stdin);
    int n,m,u,v,w;
    scanf("%d %d",&n, &m);

    while(m--)
    {
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(node(v,w));
        g[v].push_back(node(u,w));
    }

    dijkstra(n);
    for(int i=0; i<n; i++)
    {
        if(d[i]==inf)
        cout<<i<<": No Path"<<endl;
        else
        cout<<i<<": "<<d[i]<<endl;
    }
    return 0;
}


