ll rnk[1001],parent[1001];

ll find(ll x)
{
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void Union(ll x, ll y)
{
    ll xs = find(x);
    ll ys = find(y);

    if(xs == ys)
        return;

    if(rnk[xs] < rnk[ys])
        parent[xs] = ys;
    else if(rnk[xs] > rnk[ys])
        parent[ys] = xs;
    else
    {
        parent[ys] = xs;
        rnk[xs]++;
    }
}