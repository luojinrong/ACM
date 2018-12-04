#include<stdio.h>

int main()
{
	int a,b,d,c,e;
	c=0;
	scanf("%d",&a);
	for(b=1;b<a/2;b++)
	{
		d=b;
		while(c<a)
		{
			c=c+d;
			if(c==a)
			{
				printf("%d~%d",b,d);
				printf("\n");
				e=e+1;
				break;
			}
			d++;
		}
		c=0;
	}
	if(e==0)
		printf("No answer!");
}
