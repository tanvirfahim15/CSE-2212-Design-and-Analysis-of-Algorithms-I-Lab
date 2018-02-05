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
int bn(vector<int> a,int low,int high,int key){
    int m=(low+high)/2;
    if(a[m]==key)return m;
    if(high==low)return -1;
    if(a[m]>key) return bn(a,low,m-1,key);
    return bn(a,m+1,high,key);
}
int bnceil(vector<int> a,int low,int high,int key){
    int m=(low+high)/2;
    if(a[m]==key)return m+1;
    if(high==low){
        if(a[high]>key)return high;
        return high+1;
    }
    if(a[m]>key)
    return bnceil(a,low,m-1,key);
    return bnceil(a,m+1,high,key);
}
int main()
{
    //freopen ("input.txt","r",stdin);
    vector<int> a;
    a.pb(1);
    a.pb(2);
    a.pb(3);
    a.pb(5);
    a.pb(7);
    a.pb(9);
    cout<<bnceil(a,0,a.size(),22);
    return 0;
}
