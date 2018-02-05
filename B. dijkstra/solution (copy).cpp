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
int c[sz],d[sz];
void gflush(){
    loop(sz){
        c[i]=0;
        d[i]=intmax;
    }
}
bool compare(int a,int b){
    return d[a]>d[b];
}
priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
int main()
{
    freopen ("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    gflush();
    bool neg=false;
    loop(m){
        int x,y,w;
        cin>>x>>y>>w;
        if(w<0)neg=true;
        graph[x].pb(mp(y,w));
        graph[y].pb(mp(x,w));
    }
    if(neg){
        loop(n){
            cout<<i<<": Infinity"<<endl;
        }
    }
    else{
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
                    pq.push(mp(-d[v],v));
                }
            }


        }
        loop(n){
            if(d[i]==intmax){
            cout<<i<<": Infinity"<<endl;
            }
            else
            cout<<i<<": "<<d[i]<<endl;
        }

    }
    return 0;
}
