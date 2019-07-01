#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=100,i;
	int p[n];
	
	p[0]=1;
	for(i=1;i<n;i++)
	{
		int j=1;
		int k=1;
		int s=0;
		while(j>0)
		{
			j=i-(3*k*k + k)/2;
			if(j>=0)
				s=s - pow((-1),k)*(p[j]);
				
			j=i - (3*k*k-k)/2;
			if(j>=0)
				s=s - pow((-1),k)*(p[j]);
				
			k=k + 1;
		}
		p[i]=s;
	}
	return 0;
}
