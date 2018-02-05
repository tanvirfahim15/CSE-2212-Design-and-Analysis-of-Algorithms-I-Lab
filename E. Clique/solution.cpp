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
using namespace std;
#define sz 1000001
#define intmax 2147483647
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
vector<int>graph[sz],rgraph[sz],sccorder;
vector<int> scc[sz];
int sccind=0;
int c[sz],d[sz],f[sz];
stack<int>order;
int tim=0;
void gflush()
{
    loop(sz)
    {
        c[i]=0;
        d[i]=-1;
        f[i]=-1;
    }
    tim=0;
}
void dfsvisit(int n)
{
    tim++;
    d[n]=tim;
    c[n]=1;
    loop(graph[n].size())
    {
        if(c[graph[n][i]]==0)
            dfsvisit(graph[n][i]);
    }
    tim++;
    f[n]=tim;
    c[n]=2;
    order.push(n);

}
void dfs(int n)
{
    loop(n)
    {
        if(c[i]==0)
        {
            dfsvisit(i);
        }
    }
    while(!order.empty())
    {
        sccorder.push_back(order.top());
        order.pop();
    }
}
void sccvisit(int n)
{
    tim++;
    d[n]=tim;
    c[n]=1;

    scc[sccind].push_back(n);
    loop(rgraph[n].size())
    {
        if(c[rgraph[n][i]]==0)
        {
            sccvisit(rgraph[n][i]);
        }
    }
    tim++;
    f[n]=tim;
    c[n]=2;
}
int maxx(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int main()
{

   // freopen ("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    gflush();
    loop(m)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        rgraph[y].push_back(x);
    }
    dfs(n);
    gflush();
    loop(sccorder.size())
    {
        if(c[sccorder[i]]==0)
        {
            sccvisit(sccorder[i]);
            sccind++;
        }
    }
    int ans=0;
    loop(sccind)
    {
        if(!i)
            ans=scc[i].size();
        ans=maxx(ans,scc[i].size());

    }
    cout<<ans<<endl;
    return 0;
}
