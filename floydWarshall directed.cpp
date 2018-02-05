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
    /*

    5
    9
    0 1 3
    0 4 -4
    0 2 8
    1 4 7
    1 3 1
    2 1 4
    3 0 2
    3 2 -5
    4 3 6

    */
    /*
    0 0 0
    0 1 1
    0 2 -3
    0 3 2
    0 4 -4
    1 0 3
    1 1 0
    1 2 -4
    1 3 1
    1 4 -1
    2 0 7
    2 1 4
    2 2 0
    2 3 5
    2 4 3
    3 0 2
    3 1 -1
    3 2 -5
    3 3 0
    3 4 -2
    4 0 8
    4 1 5
    4 2 1
    4 3 6
    4 4 0


    */
    freopen ("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    gflush();
    loop(m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        d[x][y]=w;
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
        loopj(n)
        {
            cout<<i<<" "<<j<<" "<<d[i][j]<<endl;
        }
    }
    return 0;
}
