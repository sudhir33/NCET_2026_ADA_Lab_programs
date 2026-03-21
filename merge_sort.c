#include<stdio.h>
void merge(int *arr,int L,int M,int H)// L=4  H=9
{
	int res[H-L+1];
	int i,j,k;
	i=L,j=M+1,k=0;
	while(i<=M && j<=H)
	{
		if(arr[i]>arr[j])
		{
			res[k++]=arr[j++];
		}
		else
		{
			res[k++]=arr[i++];
		}
	}
	while(i<=M)
	{
		res[k++]=arr[i++];
	}
	while(j<=H)
	{
		res[k++]=arr[j++];
	}
	j=L;
	for(i=0;i<(H-L+1);i++)
	{
		arr[j++]=res[i];
	}
	
}
void mergeSort(int *arr,int L,int H)
{
	if(L<H)// 0<7
	{
		int M=(L+H)/2;
		mergeSort(arr,L,M);
		mergeSort(arr,M+1,H);
		merge(arr,L,M,H);// arr[L:M]  arr[M+1:H]
	}
}


int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergeSort(arr,0,n-1);// fun call  L H
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}






