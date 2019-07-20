
typedef pair<ll,ll> pi;
vector<pi> edges[1005];
vector<ll> dist(1005,1e13);

/*
    edges[u].push_back({v,w});
    edges[v].push_back({u,w});
*/
void dijkstra(ll u)
{
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pq.push({u,0});
    dist[u] = 0;

    while(!pq.empty())
    {
        u = pq.top().first;
        pq.pop();

        for(ll i=0;i<edges[u].size();i++)
        {
            ll v = edges[u][i].first;
            ll w = edges[u][i].second;

            if(dist[v] > (dist[u] + w))
            {
                dist[v] = dist[u] + w;
                pq.push({v,dist[v]});
            }
        }
    }
}
