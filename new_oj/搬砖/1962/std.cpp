#include<stdio.h>

int main()
{
	int x,sum,a,b,c,d,e;
	sum=0;
	scanf("%d",&x);
        a=x%10;
	x=x/10;
	b=x%10;
	x=x/10;
	c=x%10;
	x=x/10;
	d=x%10;
	x=x/10;
	e=x%10;
	if((a==e)&&(b==d))
		printf("yes");
	else
		printf("no");
	return 0;
}
