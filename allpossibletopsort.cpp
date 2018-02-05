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
using namespace std;
#define sz 1000001
#define intmax 2147483647
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
vector<char>node;
vector<pair<char,char>>edge;
void gnew(){
    node.clear();
    edge.clear();
}
void per(vector<char>x,int l,int h)
{

    if(l==h)
    {
        map<char,int>ctoi;
        loop(x.size()){
            ctoi[x[i]]=i;
        }
        bool pr=true;
        loop(edge.size()){
            if(ctoi[edge[i].first]>ctoi[edge[i].second])
                pr=false;
        }
        if(pr){

            loop(x.size()){
                cout<<x[i];
            }
            cout<<endl;
        }

    //    loop(x.size()){
          //  cout<<x[i]<<" ";
      //  }
        //cout<<endl;
    }
    for(int i=l;i<h;i++)
    {
        swap(x[l],x[i]);
        per(x,l+1,h);
        swap(x[l],x[i]);
    }
}
int main()
{//A B C
//A<B

    freopen ("input.txt","r",stdin);

    string input;
    getline(cin, input);

    loop(input.length()){

        node.push_back(input.at(i));
        i++;
    }
    getline(cin, input);
    loop(input.length()){

        edge.push_back(make_pair(input.at(i),input.at(i+2)));
        i+=3;
    }
    per(node,0,node.size());

    return 0;
}
