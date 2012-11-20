/*
   Problem Statement- http://www.spoj.pl/problems/NHAY/
   Date- 15-5-12
   Algorithm - Knuth-Morris-Pratt algorithm 
   		Runtime - O(len of larger string)
		a[] - to be searched for. Has 0 based indexing.
		hash[] - its prefix function. Has 1 based indexing.
   Author - Somay Jain
   */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void prefix(char a[], int *hash, int n);
int main()
{
	int k, m, j;
	scanf("%d%d", &k, &m);
	char find[k][55];
	int **hash=(int **)malloc(sizeof(int*)*k);
	int i;

	for(j=0; j<k; j++)
	{
		scanf("%s", find[j]);
		hash[j]=(int*)malloc(sizeof(int)*(strlen(find[j])+1));
	//	char a[n+1];
	//	int hash[n+1];
	//	scanf("%s%*c", a);

	//	prefix(a, hash, n);
		prefix(find[j], hash[j], strlen(find[j]));
//		for(i=1; i<=strlen(find[j]) ; i++)
//			printf("%d ", hash[j][i]);
//		printf("\n");
	}
	char in[m][55];
	int flag=0;
	for(i=0; i<m; i++)
	{
		scanf("%s", in[i]);
		if(strlen(in[i])>=47)
		{
			printf("Good\n");
			continue;
		}
		for(j=0; j<k; j++)
		{
			int q=0, count=-1,l=0;
			flag=0;
			while(in[i][l]!='\0')
			{
				count++;
				while(q>0 && find[j][q]!=in[i][l])
					q=hash[j][q];
				if(find[j][q]==in[i][l])
					q++;
				if(q==strlen(find[j]))
				{
			//		printf("%d\n", count-strlen(find[j])+1);
			//		printf("j=%d\n", j);
					printf("Good\n");
					flag=1;
				}
				if(flag==1)
					break;

				l++;
			}
			if(flag==1)
				break;
		}
		if(j==k && flag==0)
			printf("Bad\n");
		
	}
	return 0;
}
void prefix(char a[], int *hash, int n)
{
	hash[1]=0;
	int k=0, i;
	for(i=2; i<=n; i++)
	{
		
		while(k>0 && a[k]!=a[i-1])
			k=hash[k];
		if(a[k]==a[i-1])
			k++;
		hash[i]=k;
	}
}

