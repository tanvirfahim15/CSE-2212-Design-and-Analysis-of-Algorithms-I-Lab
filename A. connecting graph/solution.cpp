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
int c[sz],d[sz],f[sz];
int tim=0;
void gflush(){
    loop(sz){
        c[i]=0;
        d[i]=-1;
        f[i]=-1;
    }
}
void dfsvisit(int n){
    c[n]=1;
    tim++;
    d[n]=tim;
    loop(graph[n].size()){
        if(c[graph[n][i]]==0)
            dfsvisit(graph[n][i]);
    }
    tim++;
    f[n]=tim;
    c[n]=2;
}
int main()
{
    //freopen ("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    gflush();
    loop(m){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    int ans=0;
    loop(n){
        if(c[i]==0){
            ans++;
            dfsvisit(i);
        }
    }
    ans--;
    cout<<ans<<endl;
    return 0;
}
