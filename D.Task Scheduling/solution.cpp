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
#define sz 1002
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

struct node
{
    ULL st,en;
    bool operator<(const node& a) const
    {
        return en < a.en;
    }
};

int main()
{
    freopen ("input.txt","r",stdin);
    int t;
    cin>>t;
    loopj(t)
    {

        int n;
        ULL last=0;
        cin>>n;
        vector<node>nodes,ans;
        loop(n)
        {
            node x;
            cin>>x.st;
            nodes.pb(x);
        }
        loop(n)
        {
            cin>>nodes[i].en;
            if(nodes[i].en<last)
            last=nodes[i].en;
        }
        sort(nodes.begin(),nodes.end());

        loop(n)
        {
            if(nodes[i].st>=last)
            {
                ans.pb(nodes[i]);
                last=nodes[i].en;
            }
        }
        cout<<ans.size()<<endl;
    }

    return 0;
}
