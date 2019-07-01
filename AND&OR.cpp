#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int i,j;
 
		vector<long long int> unset[30];
		for(i=0;i<n;i++)
		{
			long long int tmp=a[i];
			for(j=0;j<30;j++)
			{
				if(!(tmp&1))
					unset[j].push_back(i);
 
				tmp=tmp>>1;
			}
		}
 
		long long int ind[30],realind[30];
		vector< pair<long long int,long long int> > dis[n];
 
		for(i=0;i<30;i++)
			realind[i]=unset[i].size()-1;
 
		for(i=n-1;i>=0;i--)
		{
			//printf("i %lld %lld\n",i,a[i]);
			long long int tmp=a[i],suband=a[i];
			for(j=0;j<30;j++)
				ind[j]=realind[j];
 
			while(suband!=0)
			{
				long long int mx=-1;
				tmp=suband;
				for(j=0;j<30;j++)
				{
					if(tmp&1)
						if(ind[j]>=0 && mx<unset[j][ind[j]])
							mx=unset[j][ind[j]];
 
					tmp=tmp>>1;
				}
 
				//printf("%lld\n",mx);
				if(mx==(-1))
				{
					dis[i].push_back(make_pair(suband,mx));
					break;
				}
 
				dis[i].push_back(make_pair(suband,mx));
 
				suband=suband&a[mx];
				for(j=0;j<30;j++)
				{
					if(ind[j]>=0 && unset[j][ind[j]]==mx)
						ind[j]--;
				}
			}
 
			if(suband==0)
				dis[i].push_back(make_pair(suband,-1));
 
			for(j=0;j<30;j++)
			{
				if(realind[j]>=0 && unset[j][realind[j]]==i)
					realind[j]--;	
			}
		}
 
	/*	for(i=0;i<n;i++)
		{
			for(j=0;j<dis[i].size();j++)
			{
				printf("%lld %lld | ",dis[i][j].first,dis[i][j].second);
			}
			printf("\n");
		}*/
 
		long long int blksiz=sqrt(n);
		long long int blkind=n/blksiz,totblk;
		if(n%blksiz!=0)
			blkind++;
 
		totblk=blkind;
		long long int blkans[n][blkind];
		memset(blkans,0,sizeof(blkans));
		blkind--;
 
		for(i=blkind*blksiz;i>=0;i=i-blksiz)
		{
			for(j=n-1;j>=i;j--)
			{
				long long int prev=j,flag=0;
				for(k=0;k<dis[j].size();k++)
				{
					pair<long long int,long long int> tmp;
					tmp=dis[j][k];
					long long int tmp1=sqrt(tmp.first);
					if((tmp1*tmp1)==tmp.first)
					{
						if(tmp.second<i)
						{
							blkans[j][blkind]=blkans[j][blkind] + prev - i + 1;
							break;
						}
						blkans[j][blkind]=blkans[j][blkind] + prev - tmp.second; 
					}
					if(tmp.second<i)
						break;
					prev=tmp.second;
				}
 
			}
			blkind--;
		}
 
		for(i=0;i<totblk;i++)
		{
			for(j=i*blksiz + 1;j<n;j++)
			{
				blkans[j][i]=blkans[j][i] + blkans[j-1][i];
			}
		}
		for(i=0;i<30;i++)
			unset[i].clear();
 
		for(i=n-1;i>=0;i--)
		{
			long long int tmp=a[i];
			for(j=0;j<30;j++)
			{
				if(!(tmp&1))
					unset[j].push_back(i);
 
				tmp=tmp>>1;
			}
		}
 
		for(i=0;i<n;i++)
			dis[i].clear();
 
		for(i=0;i<30;i++)
			realind[i]=unset[i].size()-1;
 
		for(i=0;i<n;i++)
		{
			//printf("i %lld %lld\n",i,a[i]);
			long long int tmp=a[i],suband=a[i];
			for(j=0;j<30;j++)
				ind[j]=realind[j];
 
			while(suband!=0)
			{
				long long int mx=n+2;
				tmp=suband;
				for(j=0;j<30;j++)
				{
					if(tmp&1)
						if(ind[j]>=0 && mx>unset[j][ind[j]])
							mx=unset[j][ind[j]];
 
					tmp=tmp>>1;
				}
 
				//printf("%lld\n",mx);
				if(mx==(n+2))
				{
					dis[i].push_back(make_pair(suband,n+2));
					break;
				}
 
				dis[i].push_back(make_pair(suband,mx));
 
				suband=suband&a[mx];
				for(j=0;j<30;j++)
				{
					if(ind[j]>=0 && unset[j][ind[j]]==mx)
						ind[j]--;
				}
			}
 
			if(suband==0)
				dis[i].push_back(make_pair(suband,n+2));
 
			for(j=0;j<30;j++)
			{
				if(realind[j]>=0 && unset[j][realind[j]]==i)
					realind[j]--;	
			}
		}
 
 
		vector< long long int > start[n],end[n];
		long long int prev;
		for(i=0;i<n;i++)
		{
			prev=i;
			for(j=0;j<dis[i].size();j++)
			{
				pair<long long int,long long int> tmp;
				tmp=dis[i][j];
				long long int tmp1=sqrt(tmp.first);
				if((tmp1*tmp1)==tmp.first)
				{
					if(tmp.second==(n+2))
					{
						start[i].push_back(prev);
						end[i].push_back(n-1);
					}
					else
					{
						start[i].push_back(prev);
						end[i].push_back(tmp.second-1);
					}
				}
				prev=tmp.second;
			}
		}
	}
	return 0;
}