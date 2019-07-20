ll power(ll a, ll b, ll p)
{
    if(a == 0)
        return 0;
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

ll modInverse(ll a,ll p)
{
    ll tmp = p;
    ll t2 = 0,t1 = 1;

    if(p == 1)
        return 0;

    while(a>1)
    {
        ll q = a/p;
        ll t = p;

        p = a%p;
        a = t;
        t = t2;

        t2 = t1 - q*t2;
        t1 = t;
    }

    if(t1 < 0)
        t1 = t1 + tmp;

    return t1;
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

ll mdiv(ll a,ll b)
{
    ll ans = (a * modInverse(b,MOD))%MOD;
    if(ans < 0)
        ans = ans + MOD;
    return ans;
}


// 1^k + 2^k + 3^k + ... + n^k
ll value1(ll n,ll k)
{
    vector<ll> y;

    ll sum = 0,i;
    y.push_back(0);

    for(i=1;i<=k+1;i++)
    {
        sum = add(sum,power(i,k,MOD));
        y.push_back(sum);
    }

    if(n <= k+1)
        return y[n];

    sum = 0;

    ll lag = 1;
    for(i=1;i<y.size();i++)
    {
        lag = mul(lag,sub(n,i));
        lag = mdiv(lag,sub(0,i));
    }

    for(i=0;i<y.size();i++)
    {
        sum = add(sum,mul(lag,y[i]));
        if((i+1) >= y.size())
            break;

        lag = mul(lag,mdiv(sub(n,i),sub(n,i+1)));
        lag = mul(lag,mdiv(sub(i,y.size() - 1),sub(i+1,0)));
    }
    return sum;
}

// (1^p1)*(0^p2) + (2^p1)*(1^p2) + (3^p1)*(2^p2) + ... + (n^p1)*((n-1)^p2)
ll value2(ll n,ll p1,ll p2)
{
    vector<ll> y;

    ll sum = 0,i;
    y.push_back(0);

    for(i=1;i<=p1+p2+1;i++)
    {
        sum = add(sum,mul(power(i,p2,MOD),power(i-1,p1,MOD)));
        y.push_back(sum);
    }

    if(n <= (p1 + p2 +1))
        return y[n];

    sum = 0;

    ll lag = 1;
    for(i=1;i<y.size();i++)
    {
        lag = mul(lag,sub(n,i));
        lag = mdiv(lag,sub(0,i));
    }

    for(i=0;i<y.size();i++)
    {
        sum = add(sum,mul(lag,y[i]));
        if((i+1) >= y.size())
            break;

        lag = mul(lag,mdiv(sub(n,i),sub(n,i+1)));
        lag = mul(lag,mdiv(sub(i,y.size() - 1),sub(i+1,0)));
    }
    return sum;   
}