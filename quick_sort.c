#include<stdio.h>
int partition(int *arr,int L,int H)
{
	int i,j,p;
	j=L,p=H;
	int temp;
	for(i=L;i<p;i++)
	{
		if(arr[i]<arr[p])
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			j++;
		}
	}
	temp=arr[p];
	arr[p]=arr[j];
	arr[j]=temp;
	return j;
}
void quickSort(int *arr,int L,int H)
{
	if(L<H)
	{
		int p=partition(arr,L,H);// j
		quickSort(arr,L,p-1);// 
		quickSort(arr,p+1,H);
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
	quickSort(arr,0,n-1);// fun call  L H
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

/*
Sample Input1:
8
8 1 7 2 6 3 4 5

Sample Output1:
1 2 3 4 5 6 7 8


*/



