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
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
//cout << fixed;
//cout << setprecision(2);
vector<pii>graph[sz];
vector<vector<int>> paths;
int c[sz],d[sz],p[sz];
void gflush()
{
    loop(sz)
    {
        c[i]=0;
        p[i]=-1;
        d[i]=intmax;

    }
}

bool compare(int a,int b)
{
    return d[a]>d[b];
}
priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
bool comp(pair<int,pii> a,pair<int,pii> b)
{
    if(a.first==b.first)
        return a.second.first>b.second.first;
    return a.first>b.first;
}
priority_queue<pair<int,pii>, std::vector<pair<int,pii>>, decltype(&comp)> gq(&comp);

void printpath(vector<int>path,int s,int des)
{
    if(s==des)
    {
        path.push_back(s);
        reverse(path.begin(),path.end());
        paths.pb(path);
        return;
    }
    else
    {
        path.push_back(des);
        loop(graph[des].size())
        {
            if(d[graph[des][i].first]+graph[des][i].second==d[des])
                printpath(path,s,graph[des][i].first);
        }
    }

}
int main()
{
    //freopen ("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    gflush();
    bool neg=false;
    loop(m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        if(w<0)
            neg=true;
        graph[x].pb(mp(y,w));
        graph[y].pb(mp(x,w));

    }
    if(neg)
    {
        cout<<"Not Reachable"<<endl;
    }
    else
    {
        int s=0;
        priority_queue<pii>pq;
        pq.push(mp(0,s));
        d[s]=0;
        while(!pq.empty())
        {
            int u=pq.top().second;
            pq.pop();
            loop(graph[u].size())
            {
                int v=graph[u][i].first;
                int w=graph[u][i].second;
                if(d[v]>d[u]+w)
                {
                    d[v]=d[u]+w;
                    p[v]=u;
                    pq.push(mp(-d[v],v));
                }
            }
        }
        if(p[1]==-1)
        {
            cout<<"Not Reachable"<<endl;
        }
        else
        {
            vector<int>path;
            printpath(path,0,1);
            sort(paths.begin(),paths.end());
            loopj(paths[0].size())
            {
                cout<<paths[0][j]<<endl;

            }
        }


    }
    return 0;
}
