#include<stdio.h>
#define MAX 1000000000 
#define MAX2 62500000 //max/2
#define ROOT 31622 //root
char isprime[MAX2+1];	
unsigned char hash[8];
int k;
int primes[100000000];
void sieve()
{
	//bit 0 for prime, 1 for not

	k=0;
	int i, j;
	hash[0]=1;
	for(i=1; i<8 ; i++)
	{
		hash[i]=(hash[i-1]<<1);
	}
	for(i=0; i<=MAX2; i++)
	{
		isprime[i]=0;
	}
//	for(i=1; i<=MAX; i+=1)
//		isprime[i]=1;
//	isprime[2]=1;
//	for(i=4; i<=MAX; i+=2)
//		isprime[i]=0;
//	isprime[1]=0;
	isprime[0]=1; //0x00000001
	primes[k++]=2;
	for(i=3; i<=ROOT; i+=2)
	{
		int indx=(i>>4);
		int bit=(i>>1);
		bit=(bit & 7);
		if( ( (isprime[indx]) & (hash[bit]) )== 0 )
		{
			primes[k++]=i;
	//		printf("%d\n", i);
			int inc=i<<1;	
			for(j=i*i; j<=MAX; j+=inc)
			{
				int index=(j>>4);
				int pos=((j>>1)&(7));
				isprime[index]=(isprime[index] | hash[pos]);		
			}
		}
	}
	for(i=ROOT+1; i<=MAX; i+=2)
	{
		int indx=(i>>4);
		int bit=(i>>1);
		bit=(bit & 7);
		if( ( (isprime[indx]) & (hash[bit]) )== 0 )
		{
//			printf("%d %d\n", i, k);
			primes[k++]=i;
		}

	}
}
int main()
{
	sieve();
	printf("%d\n", k);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m, i, j;
		scanf("%d%d", &n, &m);
		if(n<=2)
			printf("2\n");
		if((n&1)==0)
			n++;
		if((m&1)==0)
			m--;
		int indx1=(n>>4);
		int bit1=((n>>1)&(7));
		int indx2=(m>>4);
		int bit2=((m>>1)&(7));
		if(indx1==indx2)
		{
			for(i=bit1; i<=bit2; i++)
			{
				if((isprime[indx1] & hash[i])==0)
					printf("%d\n", ((indx1<<4)+((i<<1) +1)));
			}
		}
		else
		{
			for(i=bit1; i<8; i++)
			{
				if((isprime[indx1] & hash[i])==0)
					printf("%d\n", ((indx1<<4)+((i<<1) +1)));
			}
			for(i=indx1+1; i<indx2; i++)
			{
				for(j=0; j<8; j++)
				{
					if((isprime[i] & hash[j])==0)
						printf("%d\n", ((i<<4)+((j<<1) +1)));
						
				}
			}
				for(i=0; i<=bit2; i++)
				{
					if( (isprime[indx2] & hash[i]) ==0)
						printf("%d\n", ((indx2<<4)+((i<<1) +1)));
				}
		}
		printf("\n");
	}
	

	return 0;
}
