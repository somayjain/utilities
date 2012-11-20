// to find n^a in log n time
#include<stdio.h>
int main()
{
	int n, a, flag=0;
	scanf("%d%d", &n, &a);
	long long int power=n, ans;
	while(a!=0)
	{
		if(a%2!=0)
		{
			if(flag==0)
			{
				ans=power;
				flag=1;
			}
			else
				ans=ans*power;
		}
		power=power*power;
		a=a/2;

	}
	printf("%lld\n", ans);
	
	return 0;
}
