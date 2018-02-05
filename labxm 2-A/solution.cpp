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
#define sz 10005
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
int dp[sz];
int main()
{
    //freopen ("input.txt","r",stdin);

    int n,m,c;
    cin>>n>>m;
    loop(sz)dp[i]=0;
    dp[0]=1;
    loopj(m){
        cin>>c;
        for(int i=c;i<sz;i++){
            if(dp[i-c]==1){
                dp[i]=1;
            }
        }
    }
    if(dp[n]&&dp[n/2]){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }




    return 0;
}
