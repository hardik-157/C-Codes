void multi(ll  a[3][3], ll b[3][3])
{
    ll c[3][3],i,j,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            c[i][j] = 0;
            for(k=0;k<3;k++)
                c[i][j] = c[i][j] + a[i][k]*b[k][j];
        }
    }

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            a[i][j] = c[i][j];
}

void power(ll a[3][3],ll n)
{
    ll b[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};

    if(n==1)
        return;

    power(a,n/2);
    multi(a,a);

    if(n%2 != 0)
        multi(a,b);
    return;
}