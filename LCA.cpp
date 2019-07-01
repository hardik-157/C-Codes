#include<bits/stdc++.h>
using namespace std;
#define ll  long long int 
#define F first
#define S second
#define SETBITS(X) __builtin_popcount(x)
#define boost ios_base::sync_with_stdio(false),cin.tie(NULL);
const ll MOD = 1000000007;

// 18 > log2(100000);
ll parent[100002][18];
vector<ll> edges[100002];
ll depth[100002];


// Don't forgot to clear edges vector 
void dfs(ll u,ll p)
{
    depth[u] = depth[p] + 1;
    parent[u][0] = p;

    for(ll i=0;i<edges[u].size();i++)
    {
        if(edges[u][i] != p)
            dfs(edges[u][i],u);
    }
}

void build(ll n)
{
    ll i,j;
    for(i=1;i<18;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(parent[j][i-1] != -1)
                parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
}

ll lca(ll u,ll v)
{
    if(depth[u] > depth[v])
        swap(u,v);

    ll highdiff = depth[v] - depth[u],i;

    for(i=0;i<18;i++)
        if((highdiff>>i)&1)
            v = parent[v][i];

    if(u == v)
        return u;

    for(i=17;i>=0;i--)
    {
        if(parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int main()
{
    boost
    #ifndef ONLINE_JUDGE
        freopen("D:/Codes/C++/input.txt", "r", stdin);
        freopen("D:/Codes/C++/output.txt", "w", stdout);
    #endif
    
    memset(parent,-1,sizeof(parent));
    ll n,i;
    cin>>n;

    for(i=1;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(1,0);
    build(n);
    return 0;  
}
