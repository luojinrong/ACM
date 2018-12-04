#include<stdio.h>

int main()
{
	int a,b,c;
	scanf("%d,%d\n%d",&a,&b,&c);
	if(c==a+b)
		printf("right");
	else
	    printf("error");
}
