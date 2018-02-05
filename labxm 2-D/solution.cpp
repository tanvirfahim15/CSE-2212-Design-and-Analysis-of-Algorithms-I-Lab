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
#define sz 100002
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

ULL getSum(ULL BITree[], int index)
{
    ULL sum = 0;
    index = index + 1;
    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(ULL BITree[], int n, int index, ULL val)
{
    index = index + 1;
    while (index <= n)
    {
       BITree[index] += val;
        index += index & (-index);
    }
}

ULL *constructBITree(ULL arr[], int n)
{
    ULL *BITree = new ULL[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;

    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);


    return BITree;
}
int main()
{
    freopen ("10.in","r",stdin);
    ULL a[sz],b[sz],c[sz];
    loop(sz){
        a[i]=0;
        b[i]=0;
        c[i]=0;
    }
    int n=sz;
    ULL *BITa = constructBITree(a, n);
    ULL *BITb = constructBITree(b, n);
    ULL *BITc = constructBITree(c, n);
    cin>>n;
    vector<int> v;
    loop(n){
        int x;
        cin>>x;
        v.pb(x);
    }
    reverse(v.begin(),v.end());
    loop(n){
        int x=v[i];
        updateBIT(BITc, sz, x, getSum(BITb, x));
        updateBIT(BITb, sz, x, getSum(BITa, x));
        updateBIT(BITa, sz, x, 1);
    }
    cout<<getSum(BITc,sz)<<endl;
    return 0;
}
