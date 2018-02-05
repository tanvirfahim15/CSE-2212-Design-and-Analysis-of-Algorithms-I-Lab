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
 //cout << fixed;
//cout << setprecision(2);
//priority_queue<node, vector<node>, greater<node> > q;
/*
struct point{
    int x,y;
    point(int _x,int _y){
        x=_x;
        y=_y;
    }
};
struct Xgreater
{
    bool operator()( const point& lx, const point& rx ) const {
        return lx.x < rx.x;
    }
};

    priority_queue<point,vector<point> , Xgreater> pq;
*/
vector<int> graph[sz];
int c[sz],d[sz];
void clean(){
    loop(sz){
        c[i]=0;
        d[i]=-1;
    }
}
int main()
{
    //freopen ("input.txt","r",stdin);
    clean();
    int n,m;
    cin>>n>>m;
    loop(m){
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    bool b=true;
    int source=0;
    c[source]=1;
    d[source]=0;
    queue<int> bfs;
    bfs.push(source);
    while(!bfs.empty()){
        int u=bfs.front();
        loop(graph[u].size()){
            int v=graph[u][i];
            if(c[v]==0){
                if(c[u]==1)
                c[v]=2;
                else
                c[v]=1;
                d[v]=d[u]+1;
                bfs.push(v);
            }
            else if(c[u]==c[v]){
                b=false;
            }
        }
        bfs.pop();
    }
    if(b)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;





    return 0;
}
