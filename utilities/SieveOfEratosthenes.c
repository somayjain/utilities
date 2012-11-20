/* Problem statement- http://www.codechef.com/problems/SHUTTLE
   Date - 2-5-12
   Author- Somay Jain

   Algorithm - 	Sieve for prome numbers
   You can save the prime numbers in an array also in the sieve function.
*/

#include<stdio.h>
#define MAX 1000001
char isprime[MAX];
int primes[MAX];
void sieve()
{
	// 0 for prime, 1 for not.
	int i, j, k=0;
	isprime[1]=1;
//	isprime[2]=1;
	int start=3;
	
	for(i=start; i <= MAX ; i+=2 )
	{
//		if(i*i >=MAX/2)
//			printf("i=%d\n", i);
		if(isprime[i]==0)
		{
			isprime[i]=0;
			primes[k++]=i;
			if(i<=1000)
			for(j=i*i ; j<= MAX; j=j+2*i)
			{
			//	if(j>MAX)
			//		break;
				isprime[j]=1;
			//	printf("j=%d\n", j);
//				if(j%2==0)
//					printf("ghapla\n");
			}
		}
	}
}
int main()
{
	sieve();
	int i;
//	for(i=1; i<MAX; i+=2)
//		if(isprime[i]==0)
//			printf("%d\n", i);
//	for(i=1; i<MAX; i+=2)
	{
//		if(isprime[i]==0)
//			printf("%d\n", i);
	//	printf("%d ", isprime[i]);
	}
//	printf("\n");

	return 0;
}
