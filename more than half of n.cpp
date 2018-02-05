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

int main()
{
    freopen ("input.txt","r",stdin);
    vector<int> v;
    int n;
    cin>>n;
    loop(n){
        int x;
        cin>>x;
        v.pb(x);
    }
    int key;
    cin>>key;
    int x=upper_bound(v.begin(),v.end(),key)-lower_bound(v.begin(),v.end(),key);
    if(x>n/2&&v[n/2]==key){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }





    return 0;
}
