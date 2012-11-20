/*
   Algorithm -SSSP 
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
		
	int n, i, a ,b, j, d;
	scanf("%d", &n);
	int graph[n+1][n+1], known[n+1], parent[n+1], dist[n+1];
	for(i=0; i<n+1; i++)
	{
		known[i]=0;
		parent[i]=0;
		dist[i]=9999;
		for (j=0; j<n+1; j++)
			graph[i][j]=-9999;
	}
//	input graph here
	while(1)
	{
		scanf("%d", &a);
		if(a==-1)
			break;
		scanf("%d%d", &b, &d);
		graph[a][b]=d;
	}
	int arr[n], l=0;
	int initial;
	scanf("%d", &initial);
	known[initial]=1;
	dist[initial]=0;
	for(i=1; i<n+1; i++)
	{
		for(j=1; j<n+1; j++)
		{
			if(graph[initial][j]!=-9999 && known[j]==0)
			{
				if(dist[j] > dist[initial]+graph[initial][j])
				{
					dist[j]=dist[initial]+graph[initial][j];
					parent[j]=initial;
				}
				if(j==n)
					arr[l++]=dist[j];

			}
		}
		// finding min. Can implement minheap to reduce runtime
		int min=0;
		for(j=1; j<n+1; j++)
		{
			if(known[j]!=1 && dist[j]< dist[min])
				min=j;
		}
		known[min]=1;
		initial=min;
	}
	for(i=1; i<n+1; i++)
	{
		printf("%d ", dist[i]);
	}
	printf("\n");
	for(i=1; i<n+1; i++)
	{
		printf("%d ", parent[i]);
	}
	printf("\n");
	for(i=0; i<l; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

