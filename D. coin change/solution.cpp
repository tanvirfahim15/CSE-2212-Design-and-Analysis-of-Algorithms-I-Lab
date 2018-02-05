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
#define loopk(n) for(int p=0;p<n;p++)
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
int minim(int a,int b)
{
    if(a==-1)
        return b;
    if(b==-1)
        return a;
    if(a<b)
        return a;
    return b;
}
int addi(int a,int b)
{
    if(a==-1||b==-1)
        return -1;
    return a+b;
}
int main()
{
    freopen ("input.txt","r",stdin);
    int t;
    cin>>t;
    loopk(t)
    {
        int dp[2][30001];
        int n,k;
        cin>>n>>k;
        loop(2)
        {
            loop1j(k)
            {
                dp[i][j]=-1;
            }
        }
        loop(2)
        {
            dp[i][0]=0;
        }
        vector<int>coins;
        coins.pb(0);
        loop(n)
        {
            int c;
            cin>>c;
            coins.pb(c);
        }
        loop1(n)
        {
            loop1j(k)
            {
                if(j<coins[i])
                    dp[i%2][j]=dp[(i+1)%2][j];
                else
                    dp[i%2][j]=minim(dp[(i+1)%2][j],addi(1,dp[(i+1)%2][j-coins[i]]));
            }
        }

        cout<<dp[n%2][k]<<endl;
    }

    return 0;
}
