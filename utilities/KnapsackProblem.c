/*
 Problem Statement - http://www.spoj.pl/problems/PARTY/
 Date- 17-5-12
 Author- Somay Jain
 Algorithm- Knapsack Problem DP solution.
 */
#include<stdio.h>
int main()
{
	int w, n;
	scanf("%d%d", &w, &n);
	while(w!=0 || n!=0)
	{
		int ans[n+1][w+1];
		int cost[n+1], fun[n+1];
		int i, j;
		for(i=0; i<=w; i++)
		{
			ans[0][i]=0;
		}
		for(i=1; i<=n; i++)
			scanf("%d%d", &cost[i], &fun[i]);
		for(i=1; i<=n; i++)
		{
			for(j=0; j<cost[i]; j++)
			{
				ans[i][j]=ans[i-1][j];
			}
			for(j=cost[i]; j<=w; j++)
			{
				if(ans[i-1][j] > fun[i]+ans[i-1][j-cost[i]])
					ans[i][j]=ans[i-1][j];
				else
					ans[i][j]=fun[i]+ans[i-1][j-cost[i]];
			}
		}
		int max=ans[n][w];
		for(i=w; i>=0; i--)
		{
			if(ans[n][i]!=max)
				break;
		}
		printf("%d %d\n", i+1, max);
		scanf("%d%d", &w, &n);

	}
	return 0;
}
