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
vector<int> graph[sz];
int c[sz],d[sz];
void gflush(){
    loop(sz){
        c[i]=0;
        d[i]=-1;
    }
}
int main()
{
   // freopen ("input.txt","r",stdin);
    int n;
    cin>>n;
    loop(n-1){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    int h=ceil(log2(n));

    queue<int>bfs;
    c[0]=1;
    d[0]=0;
    bfs.push(0);
    while(!bfs.empty()){
        int cur=bfs.front();
        loop(graph[cur].size()){
            if(c[graph[cur][i]]==0){
                c[graph[cur][i]]=1;
                d[graph[cur][i]]=d[cur]+1;
                bfs.push(graph[cur][i]);
            }
        }
        bfs.pop();
    }
    bool b=true;
    loop(n){
        if(d[i]>h)b=false;
    }
    if(b)
    cout<<"Balanced"<<endl;
    else
    cout<<"Not Balanced"<<endl;
    return 0;
}
