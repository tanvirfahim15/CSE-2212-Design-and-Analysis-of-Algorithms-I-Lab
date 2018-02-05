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
#define sz 1000001
#define intmax 2147483647
#define mp make_pair
#define pii pair<int,int>
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
vector<int>graph[sz];
stack<pii>edge;
int c[sz],d[sz],p[sz],f[sz],low[sz],tim;
void gflush()
{
    loop(sz)
    {
        c[i]=0;
        d[i]=-1;
        f[i]=-1;
        p[i]=-1;
        low[i]=intmax;
    }
}
int getpcount(int n)
{
    int ret=0;
    loop(sz)
    {
        if(p[i]==n)
            ret++;
    }
    return ret;
}

void dfs(int n,int root)
{
    tim++;
    d[n]=tim;
    low[n]=tim;
    c[n]=1;
    sort(graph[n].begin(),graph[n].end());
    loop(graph[n].size())
    {
        if(c[graph[n][i]]==0)
        {
            edge.push(mp(n,graph[n][i]));
            p[graph[n][i]]=n;
            dfs(graph[n][i],root);
            if(d[n]<=low[graph[n][i]])
            {
                if(n!=root||getpcount(n)>1)
                    while(!edge.empty())
                    {
                        pii cur=edge.top();
                        edge.pop();
                        cout<<cur.first<<" "<<cur.second<<endl;
                        if(cur.first==n&&cur.second==graph[n][i])
                        {
                            cout<<endl;
                            break;
                        }
                    }
            }
            if(low[n]>low[graph[n][i]])
            {
                low[n]=low[graph[n][i]];
            }
        }
        else if(p[n]!=graph[n][i]&&c[graph[n][i]]==1)
        {
            if(low[n]>d[graph[n][i]])
                low[n]=d[graph[n][i]];
            edge.push(mp(graph[n][i],n));
        }

    }
    tim++;
    f[n]=tim;
    c[n]=2;
}
void bcc(int n,int root){
    dfs(n,root);
    while(!edge.empty())
    {
        pii cur=edge.top();
        edge.pop();
        cout<<cur.first<<" "<<cur.second<<endl;

    }
    cout<<endl;

}
int main()
{
    /*12
14
4 3
4 2
2 3
2 1
3 1
1 5
1 0
5 6
0 6
5 7
7 8
5 8
8 9
10 11*/

    freopen ("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    loop(m)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    gflush();
    loop(n){
        if(c[i]==0)bcc(i,i);
    }

    return 0;
}
