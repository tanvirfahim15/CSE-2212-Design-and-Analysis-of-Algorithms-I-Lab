#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cmath>
using namespace std;
#define sz 10001


void dfs(int n);
void dfsvisit(int n);
vector<int>graph[sz];
stack<int>order;
vector<int>orderv;
int tim=0;
int d[sz],c[sz],f[sz],p[sz],path[sz][sz];
void gflush()
{

    for(int i=0; i<sz; i++)
    {
        c[i]=0;
        d[i]=-1;
        f[i]=-1;
        p[i]=-1;
    }
}

void dfsvisit(int n)
{
    c[n]=1;
    d[n]=tim++;
    for(vector<int>::iterator it=graph[n].begin(); it!=graph[n].end(); ++it)
    {
        if(c[*it]==0)
        {
            dfsvisit(*it);
        }
    }
    f[n]=tim++;
    order.push(n);
}
int pathno(int source,int target){
    gflush();
    dfsvisit(source);
    while(!order.empty()){
        orderv.push_back(order.top());
        order.pop();
    }
    int ret=0;
    for(vector<int>::iterator it=orderv.begin();it!=orderv.end();++it){
        if(path[*it][target])
        ret++;
    }
    return ret;
}
int main()
{

    freopen ("input.txt","r",stdin);
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            path[i][j]=0;
        }
    }
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        path[x][y]=1;
    }
    cout<<pathno(0,3);

    return 0;
}
