/* Problem Statement - In an unweighted graph, find the if a path of atmost n exists between all pairs of vertices.
   Input - Make the adjacency matrix. Find A^n. Replacing in matrix multiplication, addition with OR and multiplication by AND operations.
   A^n gives the path of atmost n, likewise change A^x to find the path of atmost x.
   */
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int** mult(int **a, int **b, int n);
int main()
{
	int n, i, j;
	scanf("%d", &n);
	int **graph=(int**)malloc(sizeof(int*)*n);
	int **ans=(int**)malloc(sizeof(int*)*n);
	int **power=(int**)malloc(sizeof(int*)*n);
	// input adjacency matrix here

	for(i=0; i<n; i++)
	{
		ans[i]=(int*)malloc(sizeof(int)*n);
		graph[i]=(int*)malloc(sizeof(int)*n);
		power[i]=(int*)malloc(sizeof(int)*n);
		for(j=0; j<n; j++)
		{
			scanf("%d", &graph[i][j]);
			if(i==j)
				graph[i][j]=1;
			power[i][j]=graph[i][j];
		}
	}
//	int a=n, b=1, power=5;
	int **mul=mult(graph, graph, n);
	int a=n-1, flag=0;
	while(a!=0)
	{
		if(a%2!=0)
		{
			if(flag==0)
			{
				ans=power;
				flag=1;
			}
			else
				ans=mult(ans, power, n);
		}
		//power=power*power;
		power=mult(power, power, n);
		a=a/2;

	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
}
int** mult(int **a, int **b, int n)
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
