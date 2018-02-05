#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cmath>
using namespace std;
#define sz 1000001
void dfs(int n);
void dfsvisit(int n);
vector<int>graph[sz];
stack<int>order;
int tim=0;
int d[sz],c[sz],f[sz];
void gflush(){

    for(int i=0;i<sz;i++){
        c[i]=0;
        d[i]=-1;
        f[i]=-1;
    }
}
void dfs(int n){
    for(int i=0;i<n;i++){
        if(c[i]==0)
        dfsvisit(i);
    }
}
void dfsvisit(int n){
    c[n]=1;
    d[n]=tim++;
    for(vector<int>::iterator it=graph[n].begin();it!=graph[n].end();++it){
        if(c[*it]==0)
        dfsvisit(*it);
    }
    f[n]=tim++;
    order.push(n);
}

int main()
{
/*
    8
8
0 1
1 3
3 4
0 2
1 2
2 5
7 6
2 3
*/
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    dfs(n);
    while(!order.empty()){
        cout<<' '<<order.top();
        order.pop();
    }
    return 0;
}
