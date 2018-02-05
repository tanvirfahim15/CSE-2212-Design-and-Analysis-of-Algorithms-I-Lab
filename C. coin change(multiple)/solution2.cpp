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
    loopj(t){
        int n;
        cin>>n;
        ULL c;
        cin>>c;
        vector<ULL>coins;
        loop(n){
            ULL x;
            cin>>x;
            coins.pb(x);
        }
        sort(coins.rbegin(),coins.rend());
        int ans=0;
        loop(coins.size()){
            if(c>=coins[i])
            {
                c-=coins[i];
                ans++;
            }
        }
        if(c>0)cout<<"Impossible"<<endl;
        else cout<<ans<<endl;

    }




    return 0;
}
