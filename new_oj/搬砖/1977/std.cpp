#include<stdio.h>

int main()
{
	int n;
	double a,b=100,c=100,s=0,d;
	scanf("%d",&n);
	for(d=1;d<=n-1;d++)
	{
		c=c*0.5;
		s=s+c;
	}
	s=s*2+100;
	printf("共经过%.5f米\n",s);
	for(a=1;a<=n;a++)
	{
		b=b*0.5;
	}
	printf("第n次反弹%.5f米",b);
}
