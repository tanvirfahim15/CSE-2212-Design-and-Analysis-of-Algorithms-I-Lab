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
#define loopk(n) for(int k=0;k<n;k++)
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
int main()
{
    freopen ("input.txt","r",stdin);

    int t;
    cin>>t;
    loopk(t)
    {
        int w[301][301],dp[301][301];
        int n,m;
        cin>>n>>m;
        loop(n)
        {
            loopj(m)
            {
                cin>>w[i][j];
            }
        }
        loop(n)
        {
            loopj(m)
            {
                if(i==0&&j==0)
                    dp[i][j]=w[i][j];
                else if(i==0)
                {
                    dp[i][j]=w[i][j]+dp[i][j-1];
                }
                else if(j==0)
                {
                    dp[i][j]=w[i][j]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=w[i][j]+max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout<<dp[n-1][m-1]<<endl;
    }

    return 0;
}
