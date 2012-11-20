#include <stdio.h>
#define SWAP(a,b) {int t = a; a = b; b = t;}
bool ver[32000]={false};
int primes[4000]={0};
 
int gen() {
    int i, j, k=0;
 
 
    for (i=2 ; i<=32000 ; i++) {
        if (ver[i]==false) {
            primes[k++]=i;
            /*printf("%d\n",i);
            getchar();*/
            for (j=2 ; j>0 && i*j<=32000 ; j++) {
                ver[i*j]=true;
            }
        }
    }
    primes[0]=2;
    /*for (i=0 ; i<10 ; i++)
        printf("%d\n",primes[i]);*/
printf("%d\n", k); 
    return k;
}
 
int main() {
    int p = gen(),t,j,low,high;
    bool print;
    long long int i;
 
    scanf("%d",&t);
 
    while (t--) {
        scanf("%lld",&i);
 
	 
                   for (j=0, print=true ; primes[j]*primes[j]<=i ; j++) {
                if (i%primes[j]==0) {
			printf("%d\n", primes[j]);
                    print = false;
                    break;
                }
            }
            if (print) printf("YES\n");
	    else
		    printf("NO\n");
        }
        
    
 
 
    return 0;
}
