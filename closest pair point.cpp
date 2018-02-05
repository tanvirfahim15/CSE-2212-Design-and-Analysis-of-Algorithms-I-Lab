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
#define pp pair<point,point>
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
struct node{
    int w
    bool operator <(const node &a)const{
        return w > a.w;
    }
};
*/
struct point{
    int x,y;
    point(){}
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
struct Ygreater
{
    bool operator()( const point& lx, const point& rx ) const {
        return lx.y < rx.y;
    }
};
double getdist(point p1, point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}
pp brute(vector<point> p,int st,int en){
    point p1=p[st];
    point p2=p[en];
    double dist=getdist(p1,p2);
    for(int i=st;i<=en;i++){
        for(int j=i+1;j<=en;j++){

                if(dist>getdist(p[i],p[j])){
                    dist=getdist(p[i],p[j]);
                    p1=p[i];
                    p2=p[j];
                }

        }
    }
    return mp(p1,p2);
}
pp close(vector<point> strip,double d){
    sort(strip.begin(),strip.end(),Ygreater());
    pp ret=mp(strip[0],strip[strip.size()-1]);
    loop(strip.size()){
        for(int j=i+1;j<strip.size()&&strip[j].y-strip[i].y<d;j++){
            if(getdist(ret.first,ret.second)>getdist(strip[i],strip[j])){
                ret=mp(strip[i],strip[j]);
            }
        }
    }
    return ret;

}
pp closest(vector<point> p,int st,int en){
    if(st-en<=3)
        return brute(p,st,en);
    int m=st+en;
    m/=2;
    pp left=closest(p,st,m);
    pp right=closest(p,m+1,en);
    double d=min(getdist(left.first,left.second),getdist(right.first,right.second));
    vector<point> strip;
    for(int i=st;i<=en;i++){
        if(getdist(p[m],p[i])<=d){
            strip.pb(p[i]);
        }
    }
    return close(strip,d);
}

int main()
{
    freopen ("input.txt","r",stdin);
    int n;
    cin>>n;
    vector<point>ps;
    loop(n){
        int x,y;
        cin>>x>>y;
        ps.pb(point(x,y));
    }
    sort(ps.begin(),ps.end(),Xgreater());
    pp ans=closest(ps,0,ps.size()-1);
    cout<<ans.first.x<<" "<<ans.first.y<<endl<<ans.second.x<<" "<<ans.second.y<<endl;

    cout<<getdist(ans.first,ans.second);
    return 0;
}
