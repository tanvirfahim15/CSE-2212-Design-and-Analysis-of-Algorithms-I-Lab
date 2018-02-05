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
#define sz 10000
#define intmax 2147483647
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
#define loopk(n) for(int k=0;k<n;k++)
typedef long long LL;
typedef unsigned long long ULL;
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
//cout << fixed;
//cout << setprecision(2);

int d[sz][sz];
int minim(int a,int b)
{
    if(a==-1)
        return b;
    if(b==-1)
        return a;
    if(a<b)
        return a;
    return b;
}
int add(int a,int b)
{
    if(a==-1||b==-1)
        return -1;
    return a+b;
}
int main()
{
    freopen ("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    loop(n)
    {
        loopj(n)
        {
            d[i][j]=-1;
            if(i==j)
                d[i][j]=0;
        }
    }
    loop(m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        if(d[x][y]==-1||d[x][y]>w)
        {
            d[x][y]=w;
            d[y][x]=w;
        }

    }
    loopk(n)
    {
        loop(n)
        {
            loopj(n)
            {
                d[i][j]=minim(d[i][j],add(d[i][k],d[k][j]));
            }
        }
    }

    loop(n)
    {
        loopj(n)
        {
            if(i<j)
            {
                if(d[i][j]!=-1)
                cout<<i<<" to "<<j<<": "<<d[i][j]<<endl;
                else
                cout<<i<<" to "<<j<<": "<<"No Path"<<endl;
            }
        }
    }




    return 0;
}
