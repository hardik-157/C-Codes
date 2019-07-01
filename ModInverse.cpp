#include<bits/stdc++.h>
using namespace std;
#define ll  long long int 
#define F first
#define S second
#define SETBITS(X) __builtin_popcount(x)
#define boost ios_base::sync_with_stdio(false),cin.tie(NULL);
const ll MOD = 1000000007;


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

int main()
{
    boost
    #ifndef ONLINE_JUDGE
        freopen("D:/Codes/C++/input.txt", "r", stdin);
        freopen("D:/Codes/C++/output.txt", "w", stdout);
    #endif
    
    cout<<modInverse(2,MOD)<<endl;
    return 0;  
}
