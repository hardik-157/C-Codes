#include<bits/stdc++.h>

vector<ll> edges[1005],order;
vector<bool> visited;

void dfs(ll u)
{
    visited[u] = true;
    for(ll i = 0;i<edges[u].size();i++)
        if(!visited[edges[u][i]])
            dfs(edges[u][i]);

    order.push_back(u);
}

void topologicalSort(ll n)
{
    visited.assign(n+1,false);
    for(ll i = 1;i<=n;i++)
        if(!visited[i])
            dfs(i);

    reverse(order.begin(),order.end());
    for(ll i=0;i<order.size();i++)
        cout<<order[i]<<" ";
    cout<<endl;
}
