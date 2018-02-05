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
int d[sz],c[sz];
vector<int>p[sz],path;
void gflush(){
    loop(sz){
        d[i]=intmax;
        c[i]=0;
    }
}
bool compare(int a,int b){
    return d[a]>d[b];
}
void printpath(vector<int>path,int s,int d){
    if(s==d){
        path.push_back(s);
        reverse(path.begin(),path.end());
        loop(path.size())cout<<path[i]<<" ";
        cout<<endl;
        return;
    }
    else{
        path.push_back(d);
        loop(p[d].size()){
            printpath(path,s,p[d][i]);
        }
    }

}
int main()
{
/*5
7
0 1 2
0 3 7
0 2 2
1 4 5
1 3 2
2 3 2
3 4 3*/

    freopen ("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    loop(m){
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(y,w));
    }
    gflush();
    int source=0;
    d[source]=0;
    c[source]=1;
    priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
    pq.push(source);
    while(!pq.empty()){
        int cur=pq.top();
        loop(graph[cur].size()){
            if(d[graph[cur][i].first]>d[cur]+graph[cur][i].second){
                d[graph[cur][i].first]=d[cur]+graph[cur][i].second;
                p[graph[cur][i].first].clear();
                p[graph[cur][i].first].push_back(cur);
            }
            else if(d[graph[cur][i].first]==d[cur]+graph[cur][i].second){

                p[graph[cur][i].first].push_back(cur);
            }
            if(c[graph[cur][i].first]==0){
                c[graph[cur][i].first]=1;
                pq.push(graph[cur][i].first);
            }
        }
        pq.pop();
    }
    loop(n){
    cout<<i<<":"<<endl;
    printpath(path,0,i);
    cout<<endl;
    }

    return 0;
}
