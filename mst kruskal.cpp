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
vector<pair<pii,int>> graph;
int s[sz];
void gflush()
{
    loop(sz)
    {
        s[i]=i;
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
priority_queue<pair<pii,int>, std::vector<pair<pii,int>>, decltype(&compare)> pq(&compare);
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
v1 v2
7  6
2  8
6  5
0  1
2  5
2  3
0  7
3  4
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
        pq.push(mp(mp(x,y),w));
    }
    while(!pq.empty())
    {
        pair<pii,int> cur=pq.top();

        pq.pop();
        if(!sameset(cur.first.first,cur.first.second))
        {
            changeset(cur.first.first,cur.first.second,n);
            graph.push_back(cur);
        }
    }
    cout<<"v1 v2"<<endl;
    int ans=0;
    loop(graph.size())
    {
        cout<<graph[i].first.first<<"  "<<graph[i].first.second<<endl;
        ans+=graph[i].second;
    }
    cout<<"cost: "<<ans<<endl;


    return 0;
}
