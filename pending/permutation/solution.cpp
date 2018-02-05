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
#define loop1(n) for(int i=1;i<=n;i++)
#define loopj1(n) for(int j=1;j<=n;j++)
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
typedef long long LL;
typedef unsigned long long ULL;
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
//cout << fixed;
//cout << setprecision(2);
vector<int>graph[sz];
void paths(vector<int>c,vector<int>path,int n)
{

    if(path.size()==n)
    {
        loop(n)
        {
            if(i==0)
            printf("%d",path[i]);
            else
            printf(" %d",path[i]);
        }
        printf("\n");
    }
    else
    {
        int last=path[path.size()-1];

        loop(graph[last].size())
        {
            int cur=graph[last][i];
            if(c[cur]==0)
            {

                c[cur]=1;
                vector<int>tmp=path;
                path.pb(cur);
                paths(c,path,n);
                c[cur]=0;
                path=tmp;
            }
        }
    }
}
int main()
{
    freopen ("input.txt","r",stdin);
    //freopen ("output.txt","w",stdout);
    int n;
    cin>>n;
    loop1(n)
    {
        loopj1(n)
        {

            bool in=true;
            int x=i-j;
            if(x==0||x%2==0||x>=5||x<=-5)
                in=false;
            if(in)
                graph[i].pb(j);

        }
    }

    vector<int>c,path;
    loop(21)c.pb(0);
    loop1(n)
    {
        c[i]=1;
        path.pb(i);
        paths(c,path,n);
        path.clear();
        c.clear();
        loop(21)c.pb(0);
    }return 0;
}
