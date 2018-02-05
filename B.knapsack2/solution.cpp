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
struct node{
    int w;
    int p;
    double b;

    bool operator <(const node &a)const{
        return b > a.b;
    }
};
int main()
{
    freopen ("input.txt","r",stdin);
    int t;
    cin>>t;
    loopj(t)
    {
        int n,c;
        vector<node> nodes;
        cin>>n;
        cin>>c;
        loop(n)
        {
            node x;
            cin>>x.w;
            nodes.pb(x);
        }
        loop(n)
        {
            int x;
            cin>>x;
            double b=double(x)/nodes[i].w;
            nodes[i].b=b;
            nodes[i].p=x;
        }
        double ans=0;
        sort(nodes.begin(),nodes.end());
        loop(n)
        {
            if(c<=nodes[i].w){
                ans+=nodes[i].b*c;
                break;
            }
            ans+=nodes[i].p;
            c-=nodes[i].w;
        }
        printf("%.2f",ans);

    }

    return 0;
}
