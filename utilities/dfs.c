// input -- adjacency matrix
//known-- 0 for red, 1 for yellow, 2 for red
// 1 based indexing
// finish time incorporated.
#include<stdio.h>
#include<stdlib.h>
int count;
int* dfs(int **graph,int *known, int n, int finish[]);
int* explore(int vertex, int **graph, int *known, int n, int finish[]);
int main()
{
	int n, i, j;
	scanf("%d", &n);
	int **graph, *known;
	known=(int*)malloc(sizeof(int)*(n+1));
	graph=(int**)malloc(sizeof(int*)*(n+1));
	int finish[n+1];
	count=1;
	for(i=1; i<n+1; i++)
	{
		graph[i]=(int*)malloc(sizeof(int)*(n+1));
		known[i]=0;
		for(j=1; j<n+1; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}
	known=dfs(graph, known, n, finish);
	for(i=1; i<n+1; i++)
		printf("%d ", finish[i]);
	printf("\n");
	return 0;
}
int* dfs(int **graph, int *known, int n, int finish[])
{
	int i;
	for(i=1; i<n+1; i++)
	{
		if(known[i]==0)
		{
			known[i]=1;
			known=explore(i, graph,known, n, finish) ;
			
		}
	}
	
	return known;
}
int* explore(int vertex, int **graph, int *known, int n, int finish[])
{
	int i;
	for(i=1; i<n+1; i++)
	{
		if(graph[vertex][i]!=0 && known[i]==0 )
		{
			known[i]=1;
			known=explore(i, graph, known, n, finish);
		}

	}
	known[vertex]=2;
	finish[count++]=vertex;
	return known;
}

