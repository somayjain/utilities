#include<stdio.h>
int main()
{
	int a, b;
	int a1,b1;
	scanf("%d%d", &a, &b);
	a1=a; b1=b;
	if(b>a)
	{
		int temp=b;
		b=a;
		a=temp;
	}
	while(a%b!=0)
	{
		int temp=b;
		b=a%b;
		a=temp;
	}
	printf("%d\n", b);
//	gcd is b.
//	lcm is a1*b1/b;
	int lcm=(a1/b)*b1;
	return 0;
}
