#include<stdio.h>

int main()
{
	int n,m;
	double sum=0;
	scanf("%d",&n);
	for(m=1;m<200000;m++)
	{
		sum+=(double)1/m;
		if(sum>n)
		{
			printf("%d",m);
			break;
		}
	}
	sum=0;
	for(m=1;m<200000;m++)
	{
		sum+=(double)1/m;
		if(sum>n+1)
		{
			printf("<=m<=%d\n",m-1);
			break;
		}
	}
	return 0;
}
