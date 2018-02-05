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
#define sz 1001
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
    int ks;
    cin>>ks;
    getchar();
    while(ks--)
    {
        string s;
        getline(cin,s);
        if(s.length()==0){
            cout<<"0"<<endl;
            continue;
        }
        int dp[sz][sz];
        loop(sz)
        {
            loopj(sz)
            {
                dp[i][j]=0;
            }
        }
        loop(sz)
        {
            dp[i][i]=1;
        }
        for(int k=2; k<=s.length(); k++)
        {
            for(int i=0; i<s.length()-k+1; i++)
            {
                int j=i+k-1;
                if(k==2&&s[i]==s[j])
                    dp[i][j]=2;
                else if(s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        cout<<dp[0][s.length()-1]<<endl;
    }





    return 0;
}
