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

vector<int>graph[sz];
int d[sz],c[sz],f[sz],p[sz],low[sz],art[sz];
int tim=0;
void gflush()
{
    loop(sz)
    {
        d[i]=-1;
        f[i]=-1;
        c[i]=0;
        p[i]=-1;
        low[i]=intmax;
        art[i]=0;
    }
    tim=0;
}
void dfs(int n)
{
    tim++;
    d[n]=tim;
    c[n]=1;
    low[n]=d[n];
    loop(graph[n].size())
    {
        int cur=graph[n][i];
        if(c[cur]==0)
        {
            p[cur]=n;
            dfs(cur);
            if(low[cur]>=d[n])
                art[n]=1;
            else if(low[cur]<low[n])
            {
                low[n]=low[cur];
            }
        }
        else if(p[n]!=cur){
            if(d[cur]<low[n])
                low[n]=d[cur];
        }
    }
    tim++;
    f[n]=tim;
    c[n]=2;
}
int main()
{
    /*6
    6
    0 1
    0 2
    1 3
    2 3
    3 4
    4 5
    */

    freopen ("input.txt","r",stdin);
    gflush();
    int n,m;
    cin>>n>>m;
    loop(m)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(0);
    art[0]=0;
    int root=0;
    loop(n){
        if(p[i]==0)
            root++;
    }
    if(root>1)
        art[0]=1;
    loop(n){
    if(art[i])
        cout<<i<<" ";
    }
    return 0;
}
