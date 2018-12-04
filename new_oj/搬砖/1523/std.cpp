#include <stdio.h>    
#include <math.h>    

struct xx{
	double x, y, r;
}a[2000];
int f[2000];
int find(int x)
{
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i <= n; i++) f[i] = i;
	f[1111] = 1111;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].r);
		for (int j = 1; j<i; j++)
		if (sqrt((a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)*(a[i].y - a[j].y)) - a[i].r - a[j].r <= 0)
			f[find(j)] = find(i);
		if (fabs(a[i].y) - a[i].r<0) f[find(1111)] = f[find(i)];
		if (fabs(fabs(a[i].y) - 1000) - a[i].r<0) f[find(i)] = f[find(0)];
	}
	if (find(1111) == find(0)) printf("Bill will be bitten.");
	else
	{
		double start = 1000, end = 1000;
		for (int i = 1; i <= n; i++)
		{
			double d = fabs(a[i].x - 1000);
			if (a[i].x - a[i].r<0 && find(i) == find(0) && a[i].y - sqrt(a[i].r*a[i].r - a[i].x*a[i].x)<start) start = a[i].y - sqrt(a[i].r*a[i].r - a[i].x*a[i].x);
			if (d - a[i].r<0 && find(i) == find(0) && a[i].y - sqrt(a[i].r*a[i].r - d*d)<end) end = a[i].y - sqrt(a[i].r*a[i].r - d*d);
		}
		printf("Bill enters at (0.00, %0.2f) and leaves at (1000.00, %0.2f).", start, end);
	}
	return 0;
}
