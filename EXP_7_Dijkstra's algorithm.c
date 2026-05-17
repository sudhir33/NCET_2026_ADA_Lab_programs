//Program
#include<stdio.h>
#include<stdlib.h>
#define inf 10000
#include"heap.h"

void dijkstra(int **adjmat,int v,int *par,int *dis,int sv)
{
	par[sv]=sv;
	dis[sv]=0;
	insert_heap(sv,0);// fun call
	NODE *temp;
	int x,w,y;
	while(size!=0)
	{
		temp=delete_heap();// fun call
		x=temp->u;
		w=temp->w;
		for(y=0;y<v;y++)	
		{
			if(adjmat[x][y]!=0)
			{
				if(dis[y]>dis[x]+adjmat[x][y])
				{
					dis[y]=dis[x]+adjmat[x][y];
					par[y]=x;
					insert_heap(y,adjmat[x][y]);
				}
			}
		}
	}
}







int main()
{
	int v,e;
	scanf("%d%d",&v,&e);
	int **adjmat;
	adjmat=(int **)calloc(v,sizeof(int *));
	int i,j;
	for(i=0;i<v;i++)
	{
		adjmat[i]=(int *)calloc(v,sizeof(int));
	}
	int x,y,w;
	for(i=1;i<=e;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		adjmat[x][y]=w;
		adjmat[y][x]=w;
	}
	int par[v],dis[v];
	for(i=0;i<v;i++)
	{
		dis[i]=inf;
	}
	int sv;
	scanf("%d",&sv);
	dijkstra(adjmat,v,par,dis,sv);// fun call
	
	for(i=0;i<v;i++)
	{
		printf("%d %d\n",i,par[i]);
	}
	printf("distance\n");
	for(i=0;i<v;i++)
	{
		printf("%d %d %d\n",sv,i,dis[i]);
	}
	
	return 0;
}




/*
Sample input:
6 9
0 1 1
0 2 4
1 2 2
1 3 10
2 3 3
2 4 12
3 4 2
3 5 4
4 5 1
0
Sample output:
0 0
1 0
2 1
3 2
4 3
5 4
distance
0 0 0
0 1 1
0 2 3
0 3 6
0 4 8
0 5 9
*/


















