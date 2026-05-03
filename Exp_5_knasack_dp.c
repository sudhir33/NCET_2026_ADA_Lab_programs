

#include<stdio.h>

int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}
int knapsack(int *wt,int *va,int n,int w)
{
	int dp[n+1][w+1];
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=0;
			}
			else if(j<wt[i-1])
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],va[i-1]+dp[i-1][j-wt[i-1]]);
			}
		}
	}
	for(i=n,j=w;i!=0 && j!=0;i--)
	{
		if(dp[i][j]!=dp[i-1][j])
		{
			printf("%d %d \n",wt[i-1],va[i-1]);
			j=j-wt[i-1];
		}
	}
	return dp[n][w];
}
int main()
{
	int n;
	scanf("%d",&n);
	int wt[n],va[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&va[i]);
	}
	int w;
	scanf("%d",&w);
	int res;
	res=knapsack(wt,va,n,w);// fun call
	printf("%d",res);
	
	return 0;
}

/*
Sample Input:
4
1 3 4 5
1 4 5 7
7
Sample output:
4 5
3 4
9
*/



















