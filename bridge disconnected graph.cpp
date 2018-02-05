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
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
typedef long long LL;
typedef unsigned long long ULL;
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
//cout << fixed;
//cout << setprecision(2);
vector<int> graph[sz];
int c[sz],d[sz],f[sz],low[sz],p[sz],child[sz],art[sz];
bool root[sz];
int tim=0;
vector<pair<int,int>>bridge;
bool compare(pair<int,int> x,pair<int,int> y){
    if(x.first!=y.first)
        return x.first>y.first;
    else
        return x.second>y.second;
}

priority_queue<pair<int,int>, std::vector<pair<int,int>>, decltype(&compare)> pq(&compare);
void gflush()
{
    loop(sz)
    {
        c[i]=0;
        d[i]=-1;
        f[i]=-1;
        low[i]=intmax;
        p[i]=0;
        art[i]=0;
        child[i]=0;
        root[i]=false;
    }
    tim=0;
}
void dfsvisit(int n)
{
    c[n]=1;
    tim++;
    d[n]=tim;
    low[n]=tim;

    loop(graph[n].size())
    {
        int cur=graph[n][i];
        if(c[cur]==0)
        {
            p[cur]=n;
            child[n]++;
            dfsvisit(cur);
            if(d[n]<low[cur])
             {
                pair<int,int> pi;
                pi.first=n;
                pi.second=cur;
                if(pi.first>pi.second)
                swap(pi.first,pi.second);
                pq.push(pi);
             }
            else
                low[n]=min(low[n],low[cur]);

        }
        else if(c[cur]==1&&p[n]!=cur)
        {
            low[n]=min(low[n],d[cur]);
        }
    }
    tim++;
    f[n]=tim;
    c[n]=2;
}
void dfs(int n)
{
    loop(n)
    {
        if(c[i]==0)
        {
            root[i]=true;
            dfsvisit(i);
        }
    }
}
int main()
{

    /*
    6
6
1 3
1 2
2 3
0 1
3 4
5 0

    */
    //freopen ("input.txt","r",stdin);
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
    dfs(n);
    loop(n)
    {
        if(root[i])
        {
            art[i]=0;
            if(child[i]>1)
                art[i]=1;
        }
    }
    while(!pq.empty()){
        pair<int,int> p;
        p=pq.top();
        pq.pop();
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}
