#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000
ll tree[4*N];
ll a[N];

void build(ll node,ll start,ll end)
{
	if(start == end)
	{
		tree[node] = a[start];
	}
	else
	{
		ll mid = start + (end - start)/2;
		build(2*node, start, mid);
		build(2*node + 1, mid + 1, end);
		tree[node] = tree[2*node] + tree[2*node + 1];
	}
}

// a[idx] = val in 1 base index
void update(ll node, ll start, ll end, ll idx, ll val)
{
    if(start == end)
    {
        a[idx] = val;
        tree[node] = val;
    }
    else
    {
        ll mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update(2*node, start, mid, idx, val);
        }
        else
        {
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

// query between [l,r] in 1 base index
ll query(ll node, ll start, ll end, ll l, ll r)
{
    if(r < start or end < l)
    {
        return 0;
    }
    if(l <= start and end <= r)
    {
        return tree[node];
    }
    
    ll mid = (start + end) / 2;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}


int main()
{
	#ifndef ONLINE_JUDGE
        freopen("D:/Codes/C++/input.txt", "r", stdin);
        freopen("D:/Codes/C++/output.txt", "w", stdout);
    #endif

    ll n = 12;
	for(ll i = 1;i<=n;i++)
		a[i] = i;

	build(1,1,n);
	update(1,1,n,5,6);
	cout<<query(1,1,n,1,3)<<endl;
}
