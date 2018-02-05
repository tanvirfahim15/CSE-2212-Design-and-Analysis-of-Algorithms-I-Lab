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

int bn(vector<int> a,int st,int en,int n){
    if(st==en){
        if(a[st]>=n)
        return st;
        return st+1;
    }
    int mid=(st+en)/2;
    if(a[mid]>=n){
        return bn(a,st,mid,n);
    }
    return bn(a,mid+1,en,n);
}
int main()
{

    freopen ("input.txt","r",stdin);
    int n;
    cin>>n;
    vector<int> ns;
    loop(n){
        int x;
        cin>>x;
        ns.pb(x);
    }
    vector<int>bestend;
    bestend.pb(ns[0]);
    int p[sz];
    loop(sz){
        p[i]=-1;
    }
    loop(ns.size()){
        int ind=bn(bestend,0,bestend.size()-1,ns[i]);
        if(ind==bestend.size()){
            bestend.pb(ns[i]);
        }
        else{
            bestend[ind]=ns[i];
        }
        if(ind>0)
        p[bestend[ind]]=bestend[ind-1];
        //cout<<ind<<" "<<bestend[ind]<<" "<<p[bestend[ind]]<<endl;
    }
    ns.clear();
    int en=bestend[bestend.size()-1];
    while(p[en]!=-1){
        ns.pb(en);
        en=p[en];
    }
    ns.pb(en);
    reverse(ns.begin(),ns.end());
    loop(ns.size()){
        cout<<ns[i]<<endl;
    }




    return 0;
}
