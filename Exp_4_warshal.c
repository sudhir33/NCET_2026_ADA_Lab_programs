#include<stdio.h>
#include<limits.h>
int min(int a,int b)
{
	if(a>b)
	{
		return b;
	}
	return a;
}
void warshal(int n,int adjmat[n+1][n+1])
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(adjmat[i][k] != INT_MAX && adjmat[k][j] != INT_MAX)
                {
                    adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
                }
			}
		}
	}
	
}
int main()
{
	int n,e,i,j,u,v,w;
	scanf("%d%d",&n,&e);
	int adjmat[n+1][n+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==j)
			{
				adjmat[i][j]=0;
			}
			else
			{
				adjmat[i][j]=INT_MAX;
			}
		}
	}
	for(i=1;i<=e;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		adjmat[u][v]=w;
	}
	warshal(n,adjmat);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",adjmat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*
4 7
1 2 3
2 1 8
3 1 5
2 3 2
3 4 1
1 4 7
4 1 2

0 3 5 6
5 0 2 3
3 6 0 1
2 5 7 0



*/
