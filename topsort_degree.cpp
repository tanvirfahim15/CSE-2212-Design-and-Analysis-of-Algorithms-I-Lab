#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cmath>
using namespace std;
#define sz 100001


vector<int>graph[sz];
queue<int>topsort,in[sz];
int main()
{

    freopen ("input.txt","r",stdin);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);

        in[y].push(x);
    }
    for(int i=0;i<n;i++){
    if(in[i].size()==0)
       topsort.push(i);
    }
    while(!topsort.empty()){
        int cur=topsort.front();
        for(vector<int>::iterator it=graph[cur].begin();it!=graph[cur].end();++it){
            in[*it].pop();
            if(in[*it].size()==0)
                topsort.push(*it);
        }
        topsort.pop();
        cout<<' '<<cur;
    }


    return 0;
}
