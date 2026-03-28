#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node * next;
};
typedef struct Node NODE;
NODE *addEdge(NODE **adjlist,int x,int y)
{
	NODE *NN;
	NN=(NODE*)malloc(sizeof(NODE));
	NN->data=y;
	NN->next=NULL;
	if(adjlist[x]==NULL)
	{
		adjlist[x]=NN;
	}
	else
	{
		NODE *temp;
		temp=adjlist[x];
		adjlist[x]=NN;
		NN->next=temp;
	}
	return NN;
}

void print(NODE **adjlist,int V)
{
	int i;
	for(i=0;i<V;i++)	
	{
		printf("%d-->",i);
		NODE *temp;
		temp=adjlist[i];
		while(temp)//temp!=NULL
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

void bfs(NODE **adjlist,int V,int sv)
{
	int vis[V],i;
	for(i=0;i<V;i++)
	{
		vis[i]=0;
	}
	int queue[V],f=0,r=-1,u;
	vis[sv]=1;
	queue[++r]=sv;
	NODE *temp;
	while(f<=r)
	{
		u=queue[f++];
		printf("%d ",u);
		temp=adjlist[u];
		while(temp)
		{
			if(vis[temp->data]==0)
			{
				vis[temp->data]=1;
				queue[++r]=temp->data;
			}
			temp=temp->next;
		}
	}
}


int main()
{
	int V,E,i;
	scanf("%d%d",&V,&E);
	NODE *adjlist[V];
	for(i=0;i<V;i++)
	{
		adjlist[i]=NULL;
		
	}
	int x,y;
	for(i=1;i<=E;i++)
	{
		scanf("%d%d",&x,&y);
		adjlist[x]=addEdge(adjlist,x,y);
		adjlist[y]=addEdge(adjlist,y,x);
		
	}
	print(adjlist,V);
	int sv;
	scanf("%d",&sv);
	bfs(adjlist,V,sv);
	return 0;
}

/*
Sample Input:
6 6
0 1
0 2
1 2
2 4
3 4
5 4

Sample Output:
0-->2 1
1-->2
2-->4
3-->4
4-->
5-->4
0
0 2 1 4

*/

