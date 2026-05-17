/*
program
*/
#include<stdio.h>	
int board[20][20];
int n;

int issafe(int row,int col)// 4 3
{
	int i,j;
	// col checking
	for(i=row-1,j=col;i>=0;i--)
	{
		if(board[i][j]==1)
		{
			return 0;// not safe	
		}
	}
	// left corner
	for(i=row-1,j=col-1;i>=0 && j>=0;i--,j--)// row =3 col=4
	{
		if(board[i][j]==1)
		{
			return 0;
		}
	}
	//right corner
	for(i=row-1,j=col+1;i>=0 && j<n;i--,j++)// -1>=0 && 2<5
	{
		if(board[i][j]==1)
		{
			return 0;
		}
	}
	return 1;
	
	
}

void print_board()
{
	int i,j;
	static int count=1;
	printf("Solution:%d\n",count++);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}

void nqueen(int row)// 5
{
	if(row==n)
	{
		print_board();// fun call
		return;
	}
	int col;
	for(col=0;col<n;col++)// 
	{
		if(issafe(row,col))//funcall   // 1 true  0 false
		{
			board[row][col]=1;
			nqueen(row+1);//
			board[row][col]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);//4
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			board[i][j]=0;
		}
	}
	nqueen(0);// 0--> row
	
	return 0;
}
	
/*
Sample Input:
4
Sample Output:
Solution:1
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
Solution:2
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0
*/
	

