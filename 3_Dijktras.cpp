#include<bits/stdc++.h>
using namespace std;
void fun(int n,int m,vector<pair<pair<int,int>,int>> &g,int source)
{
    map<int,list<pair<int,int>>>adj;
    for(auto x:g)
    {
        int s=x.first.first;
        int d=x.first.second;
        int w=x.second;
        adj[s].push_back({d,w});
        adj[d].push_back({s,w});
    }
    vector<int>dist(m);
    set<pair<int,int>>st;
    for(int i=0;i<m;i++)
    {
        dist[i]=INT_MAX;
    }
    st.insert({0,source});
    dist[source]=0;
    while(!st.empty())
    {
        auto top=*(st.begin());
        int nodeDist=top.first;
        int node=top.second;
        st.erase(top);
        for(auto x:adj[node])
        {
            if(nodeDist+x.second<dist[x.first])
            {
                auto record=st.find({dist[x.first],x.first});
                if(record!=st.end())
                {
                    st.erase(record);
                }
                dist[x.first]=nodeDist+x.second;
                st.insert({dist[x.first],x.first});
            }
        }
    }
    for(auto x:dist)
    {
        cout<<x<<" ";
    }
}
int main()
{
    int n,m;
    cout<<"enter the no. of edges and vertices"<<endl;
    cin>>n>>m;
    cout<<"enter source ,dest and weight of edge"<<endl;
    vector<pair<pair<int,int>,int>> g;
    for(int i=0;i<n;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        g.push_back({{s,d},w});
    }
   fun(n,m,g,0);
}