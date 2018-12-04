#include<stdio.h>

int main()
{
	char b;
	float a,c;
	scanf("%f%c%f",&a,&b,&c);
	if(b=='+')
		printf("%.2f",a+c);
	else if(b=='-')
			printf("%.2f",a-c);
	else if(b=='*')
		printf("%.2f",a*c);
	else if(b=='/')
	       printf("%.2f",a/c);
	else
		printf("Unknown operator!");
}
