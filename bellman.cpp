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
#define loopk(n) for(int k=0;k<n;k++)
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
vector<pair<int,int>>graph[sz];
int c[sz],d[sz];
void gflush(){
    loop(sz){
        c[i]=0;
        d[i]=intmax;
    }
}
int main()
{

    freopen ("input.txt","r",stdin);
    gflush();
    int n,m;
    cin>>n>>m;
    loop(m){
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(y,w));
    }
    d[0]=0;
    loopj(m-1){
        loop(n){
            loopk(graph[i].size()){
                if(d[graph[i][k].first]>d[i]+graph[i][k].second){
                    d[graph[i][k].first]=d[i]+graph[i][k].second;
                }
            }
        }
    }
    bool b=false;
    loop(n){
            loopk(graph[i].size()){
                if(d[graph[i][k].first]>d[i]+graph[i][k].second){
                    b=true;
                }
            }
        }

    if(!b)
    loop(n)cout<<i<<":"<<d[i]<<endl;
    else
    cout<<"negative detected\n";

    return 0;
}
