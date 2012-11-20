#include<stdio.h>
#define MAX 10000000
#define ROOT 3162 //root/2
char isprime[MAX+1];
int primes[1000000];
int k;
void sieve()
{

	int i, j;
	k=0;
	for(i=1; i<=MAX; i+=2)
		isprime[i]=1;
	isprime[2]=1;
	isprime[1]=0;
	primes[k++]=2;
	for(i=4; i<=MAX; i+=2)
		isprime[i]=0;
	isprime[1]=0;
	int start=3;
	for(i=3; i<=MAX; i+=2)
	{
		if(isprime[i]==1)
		{
		//	int inc=i<<1;	
		//	int start=((((i<<1)+1)*((i<<1)+1))>>1);
		//	int inc=((i<<1)+1);
			primes[k++]=i;
			int inc=2*i;
			if(i<=ROOT)
			{
				for(j=i*i; j<=MAX; j+=inc)
				{
					isprime[j]=0;		
				}
			}
		}
	}
	
}
int main()
{
	sieve();
	
//	printf("%d\n", k);
	int t;
//	for(t=0; t<100;t++)
//		printf("%d\n", primes[t]);
//	printf("%d\n", primes[k]);
	scanf("%d", &t);
	while(t--)
	{
		long long int i, j;
		int flag=0;
		scanf("%lld", &i);
		if(i==1)
			printf("NO\n");
		else
		{
			if(i<=MAX)
			{
				if(isprime[i]==1)
					printf("YES\n");
				else
					printf("NO\n");

			}
			else
			{
				for(j=0; primes[j]*primes[j]<=i; j++)
				{
					
					if(i%primes[j]==0)
					{
						printf("NO\n");
						flag=2;
						break;
					}
					if(j==k-1)
					{
						printf("YES\n");
						flag=1;
						break;
					}
				}
				if(flag==0)
					printf("YES\n");

			}
		
		}
				
	}
//	for(i=3; i<=MAX; i+=2)
//	{
//		if(isprime[i]==1)
//			printf("%d\n", i);
//	}
	return 0;
}
