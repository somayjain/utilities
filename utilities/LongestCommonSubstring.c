/* Given two strings, find the longest common SUBSTRING of both.

  Algorithm - DP 
  Order- O(m*n)

  Date - 22-5-12

  */

#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d%*c", &t);
	while(t--)
	{
		char a[100000], b[100000];
		scanf("%s%s", a, b);
		int n=strlen(a);
		int m=strlen(b);
		int hash[n][m];
		int i, j, max=-1;
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(a[i]==b[j])
				{
					if(i!=0 && j!=0)
					{
						hash[i][j]=hash[i-1][j-1]+1;
						if(max< hash[i][j])
							max=hash[i][j];
					}
					else
					{
						hash[i][j]=1;
						if(max< hash[i][j])
							max=hash[i][j];
					}
				}
				else
					hash[i][j]=0;
			}
		}
		printf("%d\n", max);

	}
	return 0;
}
