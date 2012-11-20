#include<stdio.h>
#include<stdlib.h>
int** multiply(int **a, int **b, int n);
int main()
{
	int n;
	scanf("%d", &n);
	int **a=(int**)malloc(sizeof(int*)*n);
	int **b=(int**)malloc(sizeof(int*)*n);
	int i, j;
	for(i=0; i<n; i++)
	{
		a[i]=(int*)malloc(sizeof(int)*n);
		for(j=0; j<n; j++)
			scanf("%d", &a[i][j]);
	}
	for(i=0; i<n; i++)
	{
		b[i]=(int*)malloc(sizeof(int)*n);
		for(j=0; j<n; j++)
			scanf("%d", &b[i][j]);
	}
	int **ans=multiply(a, b, n);
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d ", ans[i][j]);

		}
		printf("\n");
	}
	return 0;
}
int** multiply(int **a, int **b, int n)
{
	int i, j, k;
	int **ret=(int**)malloc(sizeof(int*)*n);
	for(i=0; i<n; i++)
	{
		ret[i]=(int*)malloc(sizeof(int)*n);
		for(j=0; j<n; j++)
		{
			int ans=0;
			for(k=0; k<n; k++)
			{
				ans=(ans | (a[i][k] & b[k][j]));
			}
			ret[i][j]=ans;

		}
	}
	return ret;
}

