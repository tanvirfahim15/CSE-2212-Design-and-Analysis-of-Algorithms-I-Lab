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
#define sz 1000001
#define intmax 2147483647
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
typedef long long LL;
typedef unsigned long long ULL;
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
//cout << fixed;
//cout << setprecision(2);
vector<pii> graph[sz];
bool t[sz];
int p[sz],d[sz];
void gflush()
{
    loop(sz)
    {
        t[i]=false;
        p[i]=-1;
        d[i]=intmax;
    }
}
int findmin(int n)
{
    int ret=-1,dt=intmax;
    loop(n)
    {
        if(!t[i]&&d[i]<dt)
        {
            dt=d[i];
            ret=i;
        }
    }
    return ret;
}
int main()
{
    /*
    9
    14
    0 1 4
    0 7 8
    1 7 11
    1 2 8
    2 3 7
    3 4 9
    3 5 14
    4 5 10
    7 6 1
    6 5 2
    2 5 4
    2 8 2
    8 7 7
    8 6 6
    */
    /*
    v   p   d
    0   -1   0
    1   0   4
    2   1   8
    3   2   7
    4   3   9
    5   2   4
    6   5   2
    7   6   1
    8   2   2
    cost: 37


    */
    freopen ("input.txt","r",stdin);
    gflush();
    int n,m;
    cin>>n>>m;
    loop(m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(y,w));
        graph[y].push_back(make_pair(x,w));
    }
    d[0]=0;

    while(findmin(n)!=-1)
    {
        int cur=findmin(n);
        t[cur]=true;
        loop(graph[cur].size())
        {
            if(!t[graph[cur][i].first]&&d[graph[cur][i].first]>graph[cur][i].second)
            {
                d[graph[cur][i].first]=graph[cur][i].second;
                p[graph[cur][i].first]=cur;
            }
        }
    }
    int ans=0;
    cout<<"v   p   d"<<endl;
    loop(n)
    {
        cout<<i<<"   "<<p[i]<<"   "<<d[i]<<endl;
        ans+=d[i];
    }
    cout<<"cost: "<<ans<<endl;
    return 0;
}
