ll modInverse(ll a,ll p)
{
    a = a%p;
    if(a<0)
        a = a + p;
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