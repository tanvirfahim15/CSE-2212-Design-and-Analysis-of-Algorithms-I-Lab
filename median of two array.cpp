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
int a[sz],b[sz];
float brute(int ar[],int n)
{
    if((n)%2==1)
        return (ar[n/2]);
    float ret=(ar[n/2]+ar[(n-1)/2]);
    return ret/2;
}
float get_med(int a[],int b[],int n)
{
    if(brute(a,n)==brute(b,n))
        return brute(a,n);
    if(n==1)
    {

        float ret=(a[0]+b[0]);
        return ret/2;
    }
    if(n==2)
    {
        vector<int>v;
        v.pb(a[0]);
        v.pb(a[1]);
        v.pb(b[0]);
        v.pb(b[1]);
        sort(v.begin(),v.end());
        float ret=v[1]+v[2];
        return ret/2;
    }

    float up=brute(a,n);
    float down=brute(b,n);
    if(up<down)
    {
        if(n%2==1)
            return get_med(a+n/2,b,(n/2)+1);
        return get_med(a+n/2,b,(n/2));
    }
    if(up>down)
    {
        if(n%2==1)
            return get_med(a,b+n/2,(n/2)+1);
        return get_med(a,b+n/2,(n/2));
    }

}
int main()
{
    freopen ("input.txt","r",stdin);
    int n;
    cin>>n;
    loop(n)
    {
        cin>>a[i];
    }
    loop(n)
    {
        cin>>b[i];
    }

    cout<<get_med(a,b,n)<<endl;





    return 0;
}
