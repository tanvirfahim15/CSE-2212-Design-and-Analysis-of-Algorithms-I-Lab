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
    string s;
    cin>>s;
    int ans=1;
    loop(s.length()){
        int x,y,p;
        p=0;
        x=i;
        y=i+1;
        while(x>=0&&y<s.length()&&s[x]==s[y]){
            p+=2;
            x--;
            y++;
        }
        ans=max(ans,p);
        p=1;
        x=i-1;
        y=i+1;
        while(x>=0&&y<s.length()&&s[x]==s[y]){
            p+=2;
            x--;
            y++;
        }
        ans=max(ans,p);
    }
    cout<<ans<<endl;




    return 0;
}
