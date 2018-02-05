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
void gflush()
{
    loop(sz)
    {
        loopj(sz)
        {
            if(i==j)
                d[i][j]=0;
            else
                d[i][j]=-1000;
        }
    }
}
int minim(int a,int b)
{
    if(a==-1000)
        return b;
    if(b==-1000)
        return a;
    if(a<b)
        return a;
    return b;
}
int addi(int a,int b)
{
    if(a==-1000||b==-1000)
        return -1000;
    return a+b;
}
int main()
{

    freopen ("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    gflush();
    loop(m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        d[x][y]=minim(d[x][y],w);
        swap(x,y);
        d[x][y]=minim(d[x][y],w);
    }

    loopk(n)
    {
        loopj(n)
        {
            loop(n)
            {
                d[i][j]=minim(addi(d[i][k],d[k][j]),d[i][j]);
            }
        }
    }
    loop(n)
    {
        for(int j=i+1;j<n;j++)
        {
            if(d[i][j]==-1000)cout<<i<<" to "<<j<<": No Path"<<endl;
            else
            cout<<i<<" to "<<j<<": "<<d[i][j]<<endl;
        }
    }
    return 0;
}
