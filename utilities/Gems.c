/*
   Algorithm -SSSP 
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
//	printf("OK\n");
	int t;
	scanf("%d", &t);
	while(t--)
	{
	int aa, bb, cc;	
	int n, i, a ,b, d;
	long long int j;
	scanf("%d%d%d%d",&aa, &bb, &cc, &n);
//	printf("OK\n");
	int *known, *dist;
	known=(int*)malloc(sizeof(int)*n);
	dist=(int*)malloc(sizeof(int)*n);
//	printf("OK\n");
//	input graph here
/*	while(1)
	{
		scanf("%d", &a);
		if(a==-1)
			break;
		scanf("%d%d", &b, &d);
		graph[a][b]=d;
	}
	*/
/*	for(i=0; i<n; i++)
	{
		int temp=(aa*i*i + bb * i + cc)%n;
		graph[i][temp]=-1;
	}
	*/
//	printf("OK\n");
	int l;
	int mind=9999;
	for(l=0; l<n; l++)
	{
//		printf("%d\n", l);
		for(i=0; i<n; i++)
		{
			known[i]=0;
			dist[i]=9999;
		}
//		printf("%d\n", l);


		long long int initial=l;
	//	scanf("%d", &initial);
		known[initial]=1;
		dist[initial]=0;
		for(i=0; i<n; i++)
		{
		//	for(j=0; j<n; j++)
//			printf("i=%d\n", i);
//			printf("initial=%lld\n", initial);
			{
				j=((aa*initial*initial)%n + (bb*initial)%n + cc)%n;

//				printf("j=%lld\n", j);
				if(known[j]==0)
		//		if(graph[initial][j]!=-9999 && known[j]==0)
				{
					if(dist[j] > dist[initial]-1)
					{
						dist[j]=dist[initial]-1;
					}
				}
			}
			// finding min. Can implement minheap to reduce runtime
			int min=0;
			for(j=0; j<n; j++)
			{
				if(known[j]!=1 && dist[j]< dist[min])
					min=j;
			}
			known[min]=1;
			initial=min;
		}
		for(i=0; i<n; i++)
		{
			if(dist[i]< mind)
				mind=dist[i];
		}
	/*
		for(i=1; i<n+1; i++)
	{
		printf("%d ", parent[i]);
	}
	printf("\n");
	for(i=1; i<n+1; i++)
	{
		printf("%d ", known[i]);
	}
	printf("\n");*/
	}
	printf("%d\n", -1*mind+1);
	}
	return 0;
}

