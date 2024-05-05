#include<bits/stdc++.h>
using namespace std;
void fun(int n,int e,vector<pair<pair<int,int>,int>> &g)
{
    unordered_map<int,list<pair<int,int>>>adj;
    for(auto x:g)
    {
        int s=x.first.first;
        int d=x.first.second;
        int w=x.second;
        adj[s].push_back({d,w});
        adj[d].push_back({s,w});
    }
    vector<int>parent(n+1);
    vector<int>key(n+1);
    vector<bool>mst(n+1);
   
    for(int i=1;i<=n;i++)
    {
        key[i]=INT_MAX;
        parent[i]=0;
        mst[i]=false;
    }
    key[1]=0;
    parent[1]=-1;
    for(int i=1;i<=n;i++)
    {
        int mini=INT_MAX;
        int u;
        for(int j=1;j<=n;j++)
        {
            if(key[j]<mini && mst[j]==false)
            {
                mini=key[j];
                u=j;
            }
        }
        mst[u]=true;
        for(auto x:adj[u])
        {
            int v=x.first;
            int w=x.second;
            if(mst[v]==false && key[v]>w)
            {
                parent[v]=u;
                key[v]=w;
            }
        }
    }
    vector<pair<pair<int,int>,int>> result;
    for(int i=2;i<=n;i++)
    {
        result.push_back({{parent[i],i},key[i]});
    }
    for(auto x:result)
    {
        cout<<x.first.first<<" ->"<<x.first.second<<"="<<x.second<<endl;
    }
}
int main()
{
    int n,e;
    cout<<"enter no. of edges & vertices"<<endl;
    cin>>n>>e;
    cout<<"enter the source dest and weight of edges"<<endl;
    vector<pair<pair<int,int>,int>>g;
    for(int i=1;i<=e;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        g.push_back({{s,d},w});
    }
    fun(n,e,g);
}