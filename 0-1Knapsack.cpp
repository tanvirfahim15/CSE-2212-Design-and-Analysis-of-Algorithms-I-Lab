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
int knap[sz];
int main()
{
    freopen ("input.txt","r",stdin);


    int n,m,x;
    cin>>n;
    vector<int> w,p;
    loop(n)
    {
        cin>>x;
        p.pb(x);
        cin>>x;
        w.pb(x);
    }


    loopj(sz)
    {
        knap[j]=0;
    }

    int cu,pr;
    loop(n)
    {
        for(int j=sz-1; j>=w[i]; j--)
        {
            knap[j]=max(knap[j-w[i]]+p[i],knap[j]);
        }
    }
    cin>>m;
    cout<<knap[m]<<endl;

    return 0;
}


///knapsack dont need to be filled
