#include<bits/stdc++.h>
using namespace std;
#define ll  long long int 
#define F first
#define S second
#define SETBITS(X) __builtin_popcount(x)
#define boost ios_base::sync_with_stdio(false),cin.tie(NULL);
const ll MOD = 1000000007;

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

int main()
{
	boost
	#ifndef ONLINE_JUDGE
        freopen("D:/Codes/C++/input.txt", "r", stdin);
        freopen("D:/Codes/C++/output.txt", "w", stdout);
    #endif
    
    ll i;
    for(i=0;i<5;i++)
    {
        rnk[i] = 0;
        parent[i] = i;
    }

    for(i=0;i<5;i++)
        cout<<find(i)<<" ";
    cout<<endl;

    Union(0,1);
    Union(3,4);
    Union(3,0);
    
    for(i=0;i<5;i++)
        cout<<find(i)<<" ";
    cout<<endl;

    return 0;  
}
