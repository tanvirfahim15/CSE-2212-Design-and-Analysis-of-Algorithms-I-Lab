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
vector<pair<int,int>>graph[sz];
int c[sz],d[sz],p[sz],w[sz];
bool compare(int a,int b){
    return d[a]>d[b];
}
void gflush(){
    loop(sz){
        c[i]=0;
        p[i]=-1;
        w[i]=0;
        d[i]=intmax;
    }
}
void prpath(int s,int d){
    if(s==d){
        cout<<" "<<s;
        return;
    }
    else{
        prpath(s,p[d]);
        cout<<" "<<d;
    }
}
int main()
{
/*
5
10
1
2
3
4
5
0 1 10
1 2 1
0 4 5
4 1 3
1 4 2
4 2 9
4 3 2
3 0 7
3 2 6
2 3 4
*/
    freopen ("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;

    gflush();
    loop(n){
        cin>>w[i];
    }
    loop(m){
        int x,y,wt;
        cin>>x>>y>>wt;
        graph[x].push_back(make_pair(y,wt+w[y]));
    }
    int source=0;
    priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
    c[source]=1;
    d[source]=w[source];
    pq.push(source);
    while(!pq.empty()){
        int cur=pq.top();
        loop(graph[cur].size()){
            if(d[graph[cur][i].first]>d[cur]+graph[cur][i].second){
                p[graph[cur][i].first]=cur;
                d[graph[cur][i].first]=d[cur]+graph[cur][i].second;

            }
            if(c[graph[cur][i].first]==0){
                c[graph[cur][i].first]=1;
                pq.push(graph[cur][i].first);
            }
        }
        pq.pop();
    }
    loop(n){
        cout<<i<<" "<<d[i]<<" : ";
       prpath(source,i);
        cout<<endl;
    }


    return 0;
}
