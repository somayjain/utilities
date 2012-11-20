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
#include<string.h>
void prefix(char a[], int hash[], int n);
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF)
	{
		char a[n+1];
		int hash[n+1];
		scanf("%s%*c", a);
		prefix(a, hash, n);
		int i;
		char ch;
		scanf("%c", &ch);
		int q=0, count=-1, flag=0;
		while(ch !='\n')
		{
			count++;
			while(q>0 && a[q]!=ch)
				q=hash[q];
			if(a[q]==ch)
				q++;
			if(q==n)
			{
				printf("%d\n", count-n+1);
				flag=1;
			}


			scanf("%c", &ch);
		}
		if(flag==0)
			printf("\n");
		
	}
	return 0;
}
void prefix(char a[], int hash[], int n)
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
