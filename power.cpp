ll power(ll a, ll b, ll p)
{
    ll ans = 1;

    a = a%p;
    while(b>0)
    {
        if(b&1)
            ans = (ans*a)%p;

        b = b>>1;
        a = (a*a)%p;
    }
    return ans;
}


ll add(ll a,ll b)
{
    ll ans = (a + b)%MOD;
    if(ans < 0)
        ans = ans + MOD;
    return ans;
}

ll sub(ll a,ll b)
{
    ll ans = (a - b)%MOD;
    if(ans < 0)
        ans = ans + MOD;
    return ans;
}

ll mul(ll a,ll b)
{
    ll ans = (a * b)%MOD;
    if(ans < 0)
        ans = ans + MOD;
    return ans;
}

ll addpower(ll a, ll b, ll p)
{
    MOD = p;
    a = a % p;
    if(a == 0)
        return 0;

    if(b == 0)
        return 1;

    ll addans = 1;
    ll ans,i;
    vector<bool> bits;

    ans = b;
    while(ans != 0)
    {
        if(ans%2 == 0)
            bits.push_back(false);
        else
            bits.push_back(true);

        ans = ans/2; 
    }

    ans = 1;
    addans = 1;
    for(i=bits.size() - 1;i>=0;i--)
    {
        //cout<<"mul "<<addans<<" "<<ans<<endl;
        addans = add(addans,mul(sub(addans,1),ans));
        ans = mul(ans,ans);
        if(bits[i])
        {
            ans = mul(ans,a);
            addans = add(addans,ans);
        }
    }
    return addans;
}