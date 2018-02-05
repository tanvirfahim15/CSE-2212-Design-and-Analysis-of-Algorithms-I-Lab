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
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
//cout << fixed;
//cout << setprecision(2);
vector<int> graph[sz],vset;
vector<vector<pii>> bcc;
stack<pii>edge;
int c[sz],d[sz],p[sz],ch[sz],f[sz],low[sz],root[sz];
int tim=0;
bool compare(pii a,pii b)
{
    return a.first>b.first;
}
bool comp(vector<pii> a,vector<pii> b)
{
    pii ap=a[0],bp=b[0];
    if(ap.first!=bp.second)
    {
        return ap.first>bp.second;
    }
    return ap.second>bp.second;

}
void gflush()
{
    loop(sz)
    {
        c[i]=0;
        d[i]=-1;
        f[i]=-1;
        p[i]=-1;
        ch[i]=0;
        root[i]=0;
        low[i]=intmax;
    }
}
void dfsvisit(int n)
{
    c[n]=1;
    tim++;
    d[n]=tim;
    low[n]=tim;
    loop(graph[n].size())
    {
        int m=graph[n][i];
        if(c[m]==0)
        {
            edge.push(mp(n,m));
            p[m]=n;
            ch[n]++;
            dfsvisit(m);
            if(low[m]>=d[n]&&(ch[n]>1||!root[n]))
            {
                priority_queue<pii, std::vector<pii>, decltype(&compare)> pq(&compare);
                while(!edge.empty())
                {
                    bool b=false;
                    pii t=edge.top();
                    edge.pop();
                    if(t.first==n&&t.second==m)
                    {
                        b=true;
                    }
                    if(t.first>t.second)
                        swap(t.first,t.second);
                    pq.push(t);
                    if(b)
                        break;
                }
                vector<pii> in;
                while(!pq.empty())
                {
                    in.pb(pq.top());
                    pq.pop();
                }
                bcc.pb(in);
            }
            else
            {
                low[n]=min(low[n],low[m]);
            }
        }
        else if(c[m]==1&&p[n]!=m)
        {
            edge.push(mp(n,m));
            low[n]=min(d[m],low[n]);
        }
    }
    tim++;
    f[n]=tim;
    c[n]=2;
}
int main()
{
    freopen ("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    gflush();
    loop(m)
    {
        int x,y;
        cin>>x>>y;
        vset.pb(x);
        vset.pb(y);
        graph[x].pb(y);
        graph[y].pb(x);
    }
    loop(vset.size())
    {
        if(c[vset[i]]==0)
        {
            root[vset[i]]++;
            dfsvisit(vset[i]);
            priority_queue<pii, std::vector<pii>, decltype(&compare)> pq(&compare);
            vector<pii>in;
            while(!edge.empty())
            {
                pii t=edge.top();
                edge.pop();
                if(t.first>t.second)
                    swap(t.first,t.second);
                pq.push(t);
            }
            while(!pq.empty())
            {
                in.pb(pq.top());
                pq.pop();
            }
            bcc.pb(in);
        }
    }
    priority_queue<vector<pii>, std::vector<vector<pii>>, decltype(&comp)> pq(&comp);
    loop(bcc.size())
    {
        pq.push(bcc[i]);
    }
    bool f=true;
    while(!pq.empty())
    {
        if(f)
            f=!f;
        else
            cout<<"---"<<endl;
        vector<pii> x=pq.top();
        pq.pop();
        loop(x.size())
        {
            cout<<x[i].first<<" "<<x[i].second<<endl;
        }

    }
    return 0;
}
