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
#include <iostream>
#include <cstring>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define sz 30
#define intmax 2147483647
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
typedef long long LL;
typedef unsigned long long ULL;
//memset(dp, 0, sizeof(dp));
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
int main()
{
    //freopen ("input.txt","r",stdin);

    ULL dp[3][sz];
    loop(3)loopj(sz)dp[i][j]=0;
    loop(3)dp[i][0]=1;
    for(int i=1; i<sz; i++)
    {
        dp[0][i]=dp[0][i-1]+dp[1][i-1]+dp[2][i-1];
        dp[1][i]=dp[0][i];
        dp[2][i]=dp[0][i-1]+dp[1][i-1];
    }
    ULL ans[sz];
    loop(sz)ans[i]=dp[0][i]+dp[1][i]+dp[2][i];
    int t;
    cin>>t;
    loop(t)
    {
        int n;
        cin>>n;
        cout<<ans[n-1]<<endl;
    }






    return 0;
}
