

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
#define loopt(n) for(int t=0;t<n;t++)
#define loop(n) for(int i=0;i<=n;i++)
#define loopj(n) for(int j=0;j<=n;j++)
#define loop1(n) for(int i=1;i<=n;i++)
#define loop1j(n) for(int j=1;j<=n;j++)
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
    int tx;
    cin>>tx;
    for(int tt=0;tt<tx;tt++)
    {


        int dp[2][30001];
        int n,k;
        cin>>n>>k;
        vector<int>w,pi;
        w.pb(0);
        pi.pb(0);
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            w.pb(x);
        }

        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            pi.pb(x);
        }


        loop(1)
        {
            loopj(k)
            {
                dp[i][j]=0;
            }
        }

        loop1(n)
        {
            loop1j(k)
            {

                if(j<w[i])
                    dp[i%2][j]=dp[(i+1)%2][j];
                else{
                    dp[i%2][j]=max(dp[(i+1)%2][j],pi[i]+dp[(i+1)%2][j-w[i]]);
                }

            }
        }
        cout<<dp[n%2][k]<<endl;
    }

    return 0;
}
