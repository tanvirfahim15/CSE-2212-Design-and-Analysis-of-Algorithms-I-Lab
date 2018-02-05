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
#define sz 2000
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
int mem[sz][sz];
int main()
{
    freopen ("input.txt","r",stdin);

    int x;
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    loop(sz)
    {
        mem[i][0]=i;
        mem[0][i]=i;
    }
    for(int i=1; i<=s2.size(); i++)
    {
        for(int j=1; j<=s1.size(); j++)
        {
            if(s1[j-1]!=s2[i-1])
            {
                mem[i][j]=min(mem[i-1][j-1]+1,mem[i][j-1]+1);
                mem[i][j]=min(mem[i][j],mem[i-1][j]+1);
            }
            else
            {

                mem[i][j]=min(mem[i-1][j-1],mem[i][j-1]+1);
                mem[i][j]=min(mem[i][j],mem[i-1][j]+1);
            }
        }
    }
    cout<<mem[s2.size()][s1.size()]<<endl;

    return 0;
}