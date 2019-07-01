#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("D:/Codes/C++/input.txt", "r", stdin);
        freopen("D:/Codes/C++/output.txt", "w", stdout);
    #endif

	int i,j;
	/*int n=2,m=3;
	double co[n+m]={40,30,0,0,0};
	double a[m][n+m+2] = {{0,16,1,2,1,0,0},{0,9,1,1,0,1,0,0},{0,24,3,2,0,0,1,0}};*/

	int n=2,m=3;
	double co[n+m]={3,2,0,0,0};
	double a[m][n+m+2] ={{0,18,2,1,1,0,0},{0,42,2,3,0,1,0},{0,24,3,1,0,0,1}};

	double z=0,mn;
	int indj,indi;
	while(1)
	{
		z=0;
		for(i=0;i<m;i++)
		{
			z = z + a[i][0]*a[i][1];
		}

		printf("\nz %lf\n",z);
		mn=100000;
		double ans=0;
		for(i=2;i<n+m+2;i++)
		{
			ans=0;
			for(j=0;j<m;j++)
			{
				ans=ans + a[j][0]*a[j][i];
			}
			ans = ans - co[i-2];
			printf("%.2lf ",ans);
			if(ans<mn)
			{
				mn=ans;
				indj=i;
			}
		}
		if(mn>=0)
			break;
		printf("\nindj %d \n",indj);

		mn=10000;
		for(i=0;i<m;i++)
		{
			ans =a[i][1]/a[i][indj];
			printf("%.2lf ",ans);
			if(ans<mn && a[i][indj]>0)
			{
				mn=ans;
				indi=i;
			}
		}
		printf("\nindi %d\n",indi);

		a[indi][0]=co[indj-2];
		double tmp = a[indi][indj];
		for(i=1;i<n+m+2;i++)
		{
			a[indi][i] = a[indi][i]/tmp;
		}

		for(i=0;i<m;i++)
		{
			for(j=0;j<n+m+2;j++)
				printf("%.2lf ",a[i][j]);
			printf("\n");
		}

		printf("\n");
		for(i=0;i<m;i++)
		{
			if(i!=indi)
			{
				tmp = a[i][indj];
				for(j=1;j<n+m+2;j++)
				{
					a[i][j]=a[i][j] - a[indi][j]*tmp;
				}
			}
		}

		for(i=0;i<m;i++)
		{
			for(j=0;j<n+m+2;j++)
				printf("%.2lf ",a[i][j]);
			printf("\n");
		}

	}
	return 0;
}