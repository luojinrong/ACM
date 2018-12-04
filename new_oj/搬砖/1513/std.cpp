#include<stdio.h>

void px(int *p,int *m,int *n)
{
	int i; int  min = 10000000, max = -10000000;
	for (i = 0; i < 10; i++)
	{
		if (min > *(p+i))
		{
			min = *(p + i);
			*m = i;
		}
		if (max < *(p + i))
		{
			max = *(p + i);
			*n = i;
		}
	}
}
int main(void)
{
	int a[10], i, m, n;
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	px(a, &m, &n);
	i = a[n];
	a[n] = a[9];
	a[9] = i;
	i = a[m];
	a[m] = a[0];
	a[0] = i;
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
}
