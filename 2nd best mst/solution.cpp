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
#define loopk(n) for(int k=0;k<n;k++)
typedef long long LL;
typedef unsigned long long ULL;
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
//cout << fixed;
//cout << setprecision(2);
vector<pair<pii,int>> graph,sgraph,tmp;
int s[sz],c[sz];
void gflush()
{
    loop(sz)
    {
        s[i]=i;
        c[i]=0;
    }
}
bool compare(pair<pii,int> a,pair<pii,int> b)
{
    return a.second>b.second;
}
bool sameset(int x,int y)
{
    return s[x]==s[y];
}
void changeset(int x,int y,int n)
{
    x=s[x];
    y=s[y];
    loop(sz)
    {
        if(s[i]==x)
            s[i]=y;
    }
}

int main()
{
    freopen ("input.txt","r",stdin);
    gflush();
    int n,m;
    cin>>n>>m;
    priority_queue<pair<pii,int>, std::vector<pair<pii,int>>, decltype(&compare)> pq(&compare);
    loop(m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        pq.push(mp(mp(x,y),w));
    }
    while(!pq.empty())
    {
        sgraph.pb(pq.top());
        pq.pop();
    }
    loop(sgraph.size())
    {
        pair<pii,int> cur=sgraph[i];

        if(!sameset(cur.first.first,cur.first.second))
        {
            changeset(cur.first.first,cur.first.second,n);
            graph.push_back(cur);
        }
    }
    int mst=0,smst=intmax;
    loop(graph.size())
    {
        mst+=graph[i].second;
    }
    cout<<mst<<endl;
    loopj(graph.size())
    {
        gflush();
        tmp.clear();
        int stmp=0;
        loop(sgraph.size())
        {
            pair<pii,int> cur=sgraph[i];
            if(cur.first.first==graph[j].first.first&&cur.first.second==graph[j].first.second)
            {

            }
            else
            {
                if(!sameset(cur.first.first,cur.first.second))
                {
                    changeset(cur.first.first,cur.first.second,n);
                    tmp.push_back(cur);
                    stmp+=cur.second;
                }
            }
        }


        if(stmp<smst&&stmp>mst)
            smst=stmp;

    }
    cout<<smst<<endl;
    return 0;
}
