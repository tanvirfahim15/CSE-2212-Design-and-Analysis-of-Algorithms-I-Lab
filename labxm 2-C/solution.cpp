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
#define sz 1000001
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
    freopen ("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    if(n<2||m<2){
        cout<<"Impossible"<<endl;
    }
    else if(n%2&&m%2){
        cout<<"Impossible"<<endl;
    }
    else if(n%2==0&&m%2==0){
        n/=2;
        m/=2;
        ULL ans=n;
        ans*=m;
        cout<<ans<<endl;
    }
    else{
        if(m%2){
            swap(n,m);
        }
        n-=3;
        n/=2;
        m/=2;
        ULL ans=n;
        ans*=m;
        ans+=2*m;
        cout<<ans<<endl;

    }





    return 0;
}
