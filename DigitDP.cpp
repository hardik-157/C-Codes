vector<ll> digits;
ll d,k;
ll dp[12][12][2];

ll digitDP(int pos,int cnt,int tight)
{
    if(cnt > k)
        return 0;

    if(pos ==  digits.size())
    {
        if(cnt == k)
            return 1;
        return 0;
    }

    if(dp[pos][cnt][tight] != -1)
        return dp[pos][cnt][tight];


    ll ans = 0;
    ll k = (tight)?digits[pos] : 9;

    for(i=0;i<=k;i++)
    {
        ll ntight = (digits[pos] == i) ? tight : 0;
        ll ncnt = cnt;
        if(d == i)
            ncnt++;
        ans = ans + digitDP(pos + 1,ncnt,ntight);
    }

    return dp[pos][cnt][tight] = ans;
}

ll solve(ll b)
{
    digits.clear();
    while(b>0)
    {
        digits.push_back(b%10);
        b = b/10;
    }
    reverse(digits.begin(),digits.end());

    memset(dp,-1,sizeof(dp));

    return digitDP(0,0,1);
}