#include <stdio.h>
/*
   03	Takes a, b as input.
   04	Returns gcd(a, b).
   05	Updates x, y via pointer reference.
   06	*/
int Extended_Euclid(int A, int B, int *X, int *Y)
{
	int x, y, u, v, m, n, a, b, q, r;

	/* B = A(0) + B(1) */
	x = 0; y = 1;

	/* A = A(1) + B(0) */
	u = 1; v = 0;

	for (a = A, b = B; 0 != a; b = a, a = r, x = u, y = v, u = m, v = n)
	{
		/* b = aq + r and 0 <= r < a */
		q = b / a;
		r = b % a;

		/* r = Ax + By - aq = Ax + By - (Au + Bv)q = A(x - uq) + B(y - vq) */
		m = x - (u * q);
		n = y - (v * q);
	}  

	/* Ax + By = gcd(A, B) */
	*X = x; *Y = y;

	return b;
}

int main()
{
	int t, count;
	scanf("%d", &t);
	double x1, x2, y1, y2;
	double a, b, c;
	double aa, bb, cc;
	int x, y, g;
	while(t--)
	{
		count=0;
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		a=y1-y2; b=x2-x1;
		c=y1*x2  - x1*y2;

		a=100*a; b=100*b; c=100*c;
		printf("%d %d %d\n", (int)a, (int)b, (int)c);
		g = Extended_Euclid(abs((int)a), abs((int)b), &x, &y);
		if((int)c%g!=0)
		{
			printf("0\n");
			return;
		}
		else
		{
			a=a/g; b=b/g; c=c/g;
		}
		printf("%d\n", g);
		g = Extended_Euclid((int)a, (int)b, &x, &y);
		printf("%d %d\n", x, y);


		

	}
//	int a, b, x, y, g;
//	scanf("%d %d", &a, &b);
//	g = Extended_Euclid(a, b, &x, &y);
//	printf("X = %d; Y = %d; G = %d\n", x, y, g);
	return 0;
}
