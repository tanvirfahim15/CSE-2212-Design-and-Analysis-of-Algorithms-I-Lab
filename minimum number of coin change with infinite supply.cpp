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
#define sz 10001
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
int mem[sz];
int mini(int a,int b){
    if(a==-1)return b;
    if(b==-1)return a;
    if(a<b)return a;
    return b;
}
int main()
{
    freopen ("input.txt","r",stdin);
    int n,m;
    cin>>m>>n;
    vector<int> cs;
    loop(n)
    {
        int x;
        cin>>x;
        cs.pb(x);
    }
    sort(cs.begin(),cs.end());
    loop(sz)
    {
        mem[i]=-1;
    }
    mem[0]=0;
    loop(cs.size())
    {
        for(int j=cs[i]; j<sz; j++)
        {
            if(mem[j-cs[i]]!=-1)
            {
                mem[j]=mini(mem[j],mem[j-cs[i]]+1);

            }
        }
    }
    cout<<mem[m]<<endl;

    return 0;
}

//Given infinite coins with fixed values.
//output minimum number of coin
