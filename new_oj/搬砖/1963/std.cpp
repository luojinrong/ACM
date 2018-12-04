#include<stdio.h>

int main()
{
	int a,i,c;
	scanf("%d",&a);
	for(i=100;i<=999;i++)
		if(a%i==0)
		{
			c=i;
		}
	printf("%d",c);
}
