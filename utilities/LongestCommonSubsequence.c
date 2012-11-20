/* Problem Statement - Given two strings, find the length of the lingest common subsequence of the strings.
   Note - We can jump over some characters to get the largest SUBSEQUENCE.

   Algorithm - DP
   Order- O(m*n)
   */
#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char a[100000], b[100000];
		scanf("%s%s", a, b);
		int n=strlen(a);
		int m=strlen(b);
		int hash[n+1][m+1];
		//the first row and column is to be filled with zeros.
		int i, j, max=-1;
		for(i=0; i<=n; i++)
			hash[i][0]=0;
		for(i=0; i<=m; i++)
			hash[0][i]=0;
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				if(a[i-1]==b[j-1])
				{
					hash[i][j]=hash[i-1][j-1]+1;
					if(max< hash[i][j])
					{
						max=hash[i][j];
				//		printf("%c %d %d\n", a[i-1], i, j);
					}
				}
				else
				{
					if(hash[i-1][j] > hash[i][j-1])
						hash[i][j]=hash[i-1][j];
					else
						hash[i][j]=hash[i][j-1];
					if(max< hash[i][j])
						max=hash[i][j];

				}

			}
		}
		for(i=0; i<=n; i++)
		{
			for(j=0; j<=m; j++)
			{
				printf("%d ", hash[i][j]);

			}
			printf("\n");
		}
		printf("%d\n", max);

	}
	return 0;
}
