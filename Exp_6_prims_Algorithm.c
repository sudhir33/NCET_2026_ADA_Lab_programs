//Program
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int x,y,w;
};
typedef struct Node NODE;
NODE *heap[100];
int size=0;

int find_min_3(int x,int y,int z)
{
	if(heap[x]->w<heap[y]->w && heap[x]->w<heap[z]->w)
	{
		return x;
	}
	if(heap[y]->w<heap[x]->w && heap[y]->w<heap[z]->w)
	{
		return y;
	}
	return z;
}
int find_min_2(int x,int y)
{
	if(heap[x]->w>heap[y]->w)
	{
		return y;
	}
	return x;
}



void insert_heap(int x,int y,int w)
{
	NODE *NN;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->x=x;
	NN->y=y;
	NN->w=w;
	heap[size]=NN;
	int i=size;
	while(1)
	{
		int par=(i-1)/2;
		if(heap[i]->w>heap[par]->w  || i==0)
		{
			break;
		}
		NODE *temp;
		temp=heap[i];
		heap[i]=heap[par];
		heap[par]=temp;
		i=par;	
	}
	size++;
}

NODE * delete_heap()
{
	NODE *root;
	root=heap[0];
	int i=0;
	heap[0]=heap[size-1];//last ele is copied to first ele
	int left,right;
	int min;
	while(1)
	{
		left=2*i+1;
		right=2*i+2;
		if(left<size && right<size)
		{
			min=find_min_3(i,left,right);// fun call
		}
		else if(left<size)
		{
			min=find_min_2(i,left);// fun call
		}
		else
		{
			break;
		}
		
		if(min==i)
		{
			break;
		}
		NODE *temp;
		temp=heap[min];
		heap[min]=heap[i];
		heap[i]=temp;
		i=min;
	}
	
	size--;
	return root;
}


int prims(int **adjmat,int v,int sv,int **res,int *vis)
{
	vis[sv]=1;
	int count=1,tw=0;
	int i,j;
	i=sv;
	for(j=0;j<v;j++)
	{
		if(adjmat[i][j]!=0)
		{
			insert_heap(i,j,adjmat[i][j]);// fun call
		}
	}
	NODE *temp;
	while(count!=v)
	{
		temp=delete_heap();// x y w
		if(vis[temp->y]==1)
		{
			continue;
		}
		i=temp->y;
		for(j=0;j<v;j++)
		{
			if(adjmat[i][j]!=0 && vis[j]!=1)
			{
				insert_heap(i,j,adjmat[i][j]);// fun call
			}
		}
		vis[i]=1;
		count++;
		res[temp->x][temp->y]=temp->w;
		tw+=temp->w;
		
	}
	return tw;
}

int main()
{
	int v,e;
	scanf("%d%d",&v,&e);
	int **adjmat,**res;
	adjmat=(int **)calloc(v,sizeof(int *));
	res=(int **)calloc(v,sizeof(int *));
	int i,j;
	for(i=0;i<v;i++)
	{
		adjmat[i]=(int *)calloc(v,sizeof(int));
		res[i]=(int *)calloc(v,sizeof(int));
	}
	int x,y,w;
	for(i=1;i<=e;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		adjmat[x][y]=w;
		adjmat[y][x]=w;
	}
	int vis[v];
	for(i=0;i<v;i++)
	{
		vis[i]=0;
	}
	int sv;
	scanf("%d",&sv);
	int tw;
	tw=prims(adjmat,v,sv,res,vis);// fun call
	printf("%d\n",tw);
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
	
	
	
	
		
	return 0;
}





	
	
	
	
	
	
	
	
	
	
	
	
	
	
