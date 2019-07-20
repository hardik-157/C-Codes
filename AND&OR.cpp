const ll k = 30;
vector<ll> unset[k];

struct data
{
    ll value, start, finish, ind;
    data(ll ind, ll value, ll start, ll finish)
    {
        this->ind = ind;this->value = value;this->start = start;this->finish = finish;
    }
};

ll upper_bound(ll x,ll nbit)
{
    ll l = 0,h = unset[nbit].size();
    while(l<h)
    {
        ll mid = l + (h-l)/2;
        if(x >= unset[nbit][mid])
            l = mid + 1;
        else
            h = mid;
    }
    return l;
}

void AndOr(ll a[],ll n)
{
    ll i,j;

    // OR operation if((a[i]>>j)&1)
    for(i=0;i<n;i++)
        for(j=0;j<k;j++)
            if(!((a[i]>>j)&1))
                unset[j].push_back(i);

    vector<data> answers;
    for(i=0;i<n;i++)
    {
        ll pre = a[i];
        ll curr = i;
        ll closestChange;
        //OR operation pre < 1LL<<(k+1)
        while(pre != 0)
        {
            closestChange = n;
            for(j=0;j<k;j++)
            {
            	// OR operation if(!((pre>>j)&1))
                if((pre>>j)&1)
                {
                    ll tmp = upper_bound(i,j);
                    if(tmp != unset[j].size() && closestChange > unset[j][tmp])
                        closestChange = unset[j][tmp];
                }
            }
            if(closestChange == n)
            {
                answers.push_back(data(i,pre,curr,n));
                break;
            }
            answers.push_back(data(i,pre,curr,closestChange - 1));
            //OR operation pre = pre | a[closestChange];
            pre = pre & a[closestChange];
            curr = closestChange;
        }
        if(closestChange != n)
            answers.push_back(data(i,0,curr,n));
    }

    for(i=0;i<answers.size();i++)
        cout<<answers[i].ind<<" "<<answers[i].value<<" "<<answers[i].start<<" "<<answers[i].finish<<endl;
}