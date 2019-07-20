ll n,q;
ll ans;

ll answers[100005];
ll block_size;

vector< pair<pair<ll,ll>, ll> > queries;

bool MoCmp(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b)
{
    if((a.first.first/block_size) != (b.first.first/block_size))
        return (a.first.first/block_size) < (b.first.first/block_size);

    return a.first.second < b.first.second;
}

void add(ll x)
{
    
}

void remove(ll x)
{

}

int main()
{
    boost
    #ifndef ONLINE_JUDGE
        freopen("D:/Codes/C++/input.txt", "r", stdin);
        freopen("D:/Codes/C++/output.txt", "w", stdout);
    #endif
    
    ll t; cin>>t;
    while(t--)
    {
        queries.clear();
        ans = 0;
        cin>>n>>q;

        block_size = sqrt(n);

        ll a[n+1],i;
        for(i=1;i<=n;i++)
            cin>>a[i];

        for(i=0;i<q;i++)
        {
            ll l,r;
            cin>>l>>r;
            queries.push_back(make_pair(make_pair(l,r),i));
        }

        sort(queries.begin(), queries.end(), MoCmp);
        
        ll currL = 1,currR = 0;

        for(i=0;i<queries.size();i++)
        {
            ll l = queries[i].first.first;
            ll r = queries[i].first.second;

            while(currR < r)
            {
                currR++;
                add(a[currR]);
            }

            while(currR > r)
            {
                remove(a[currR]);
                currR--;
            }

            while(currL < l)
            {
                remove(a[currL]);
                currL++;
            }

            while(currL > l)
            {
                currL--;
                add(a[currL]);
            }

            answers[queries[i].second] = ans;
        }

        for(i=0;i<queries.size();i++)
            cout<<answers[i]<<endl;
    }
    return 0;  
}
