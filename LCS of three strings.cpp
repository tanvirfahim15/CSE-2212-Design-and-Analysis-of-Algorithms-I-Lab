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
#define sz 100
#define intmax 2147483647
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
#define loopk(n) for(int k=0;k<n;k++)
typedef long long LL;
typedef unsigned long long ULL;
//cout << fixed;
//cout << setprecision(2);
//priority_queue<node, vector<node>, greater<node> > q;
/*
struct point{
    int x,y;
    point(int _x,int _y){
        x=_x;
        y=_y;
    }
};
struct Xgreater
{
    bool operator()( const point& lx, const point& rx ) const {
        return lx.x < rx.x;
    }
};

    priority_queue<point,vector<point> , Xgreater> pq;
*/
int dp[sz][sz][sz],n,m,o;
string X,Y,Z;
int f(int l1,int l2,int l3){
    if(l1<0||l2<0||l3<0)
        return 0;
    if(dp[l1][l2][l3]!=-1) return dp[l1][l2][l3];
    if(X[l1]==Y[l2]&&Y[l2]==Z[l3]){
        dp[l1][l2][l3]= 1+f(l1-1,l2-1,l3-1);
    }
    else{
        dp[l1][l2][l3]=max(f(l1-1,l2,l3),max(f(l1,l2-1,l3),f(l1,l2,l3-1)));
    }
    return dp[l1][l2][l3];
}
int main()
{
    //freopen ("input.txt","r",stdin);
    X = "AGsGT12";
    Y = "sw12TXAYB";
    Z = "ws12XBA";
    loop(sz)
    {
        loopj(sz)
        {
            loopk(sz){
                dp[i][j][k]=-1;
            }
        }
    }
    n=X.length();
    m=Y.length();
    o=Z.length();
    cout<<f(n-1,m-1,o-1);


    return 0;
}
