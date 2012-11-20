/* Problem Statement - In an unweighted graph, find the if a path of atmost n exists between all pairs of vertices.
   Input - Make the adjacency matrix. Find A^n. Replacing in matrix multiplication, addition with OR and multiplication by AND operations.
   A^n gives the path of atmost n, likewise change A^x to find the path of atmost x.
   */
/* Eg- 
5
9999 3 8 9999 -4
9999 0 9999 1 7
9999 4 0 9999 9999
2 9999 -5 0 9999
9999 9999 9999 6 0

op-
0 1 -3 2 -4 
3 0 -4 1 -1 
7 4 0 5 3 
2 -1 -5 0 -2 
8 5 1 6 0
*/

#include<stdio.h>
#include<stdlib.h>
int** mult(int **a, int **b, int n);
int main()
{
	int n, i, j, aa, b, c;
	scanf("%d%d%d%d",&aa, &b, &c, &n);
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
			graph[i][j]=-9;
//			scanf("%d", &graph[i][j]);
//			if(i==j)
//				graph[i][j]=0;
//			power[i][j]=graph[i][j];
		}
	}
	for(i=0; i<n; i++)
		graph[i][i]=0;
	for(i=0; i<n; i++)
	{
		int temp=(aa*i*i+ b*i + c) %n;
		if(i==temp)
			graph[i][temp]=0;
		else

			graph[i][temp]=-1;
		power[i][j]=graph[i][j];
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n;j++)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
//	int a=n, b=1, power=5;
	int **mul=mult(graph, graph, n);
	int a=n, flag=0;
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
//	for(i=0; i<n; i++)
	i=2;
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
			int ans=a[i][j];

			for(k=0; k<n; k++)
			{
				if(ans > a[i][k]+b[k][j])
					ans=a[i][k]+b[k][j];
			}
			ret[i][j]=ans;

		}
	}
	return ret;
}
