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
#define loopk(n) for(int k=0;k<n;k++)
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
vector<pair<int,int>>graph[sz];
int c[sz],d[sz];
void gflush()
{
    loop(sz)
    {
        c[i]=0;
        d[i]=intmax;
    }
}
int main()
{

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
    //d[0]=0;

    int k;
    cin>>k;
    loop(k)
    {
        int x;
        cin>>x;
        d[x]=0;
    }
    loopj(n)
    {
        loop(n)
        {
            loopk(graph[i].size())
            {
                if(d[graph[i][k].first]>d[i]+graph[i][k].second)
                {
                    d[graph[i][k].first]=d[i]+graph[i][k].second;
                }
            }
        }
    }

    loop(n){
        if(d[i]==intmax)
        cout<<i<<": No Path"<<endl;
        else
        cout<<i<<": "<<d[i]<<endl;
    }

    return 0;
}
