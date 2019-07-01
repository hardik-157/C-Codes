#include<bits/stdc++.h>
using namespace std;
#define ll  long long int 
#define F first
#define S second
#define SETBITS(X) __builtin_popcount(x)
#define boost ios_base::sync_with_stdio(false),cin.tie(NULL);
const ll MOD = 1000000007;

ll gcd(ll a, ll b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
}

int** gcdtable(int n)
{
	int** gcd = new int*[n+1];
	for(int i = 1;i <= n;i++)
	{
		gcd[i] = new int[n+1];
	}
	
	for(int i = 1;i <= n;i++)
	{
		gcd[i][i] = i;
		for(int j = i+1;j <= n;j++)
		{
			gcd[j][i] = gcd[i][j] = gcd[i][j-i];
		}
	}
	return gcd;
}

int main()
{
	int i,j;
	int** g	= gcdtable(200);
	
	for(i=1;i<=20;i++)
	{
		for(j=1;j<=20;j++)
		{
			printf("%d ",g[i][j]);
		}
		printf("\n");
	}
	return 0;
}
