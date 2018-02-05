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
#define sz 100005
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
LL dp[3][sz];
int main()
{
    freopen ("7.in","r",stdin);

    loop(3)loopj(sz)dp[i][j]=0;
    vector<int> v;
    int n;
    cin>>n;
    loop(n)
    {
        int x;
        cin>>x;
        v.pb(x);
    }
    reverse(v.begin(),v.end());
    loop(sz)dp[0][i]=1;
    dp[1][0]=0;
    dp[2][0]=0;
    for(int i=1; i<n; i++)
    {
        for(int k=1; k<3; k++)
        {
            LL sum=0;
            for(int j=0; j<i; j++)
            {
                if(v[j]<=v[i])
                {
                    sum+=dp[k-1][j];
                }
            }
            dp[k][i]=sum;
        }
    }


    LL ans=0;
    loop(n)ans+=dp[2][i];
    cout<<ans<<endl;





    return 0;
}
