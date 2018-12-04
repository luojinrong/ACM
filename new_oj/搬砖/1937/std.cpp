#include<stdio.h>

int main()
{
	int i,k,inverse,a,b,c;
	scanf("%d",&i);
	k=i;
	inverse=0;
	while(k>0) 
	{
	    inverse=inverse*10+k%10;
	    k=k/10;
	}
	a=(i==inverse);
	k=i*i;
	inverse=0;
	while(k>0) 
	{
	    inverse=inverse*10+k%10;
	    k=k/10;
	}
	b=(i*i==inverse);
	k=i*i*i;
	inverse=0;
	while(k>0) 
	{
	    inverse=inverse*10+k%10;
	    k=k/10;
	}
	c=(i*i*i==inverse);
	if(a&&b&&c)
		printf("%d是三重回文数\n",i);
	else
		printf("%d不是三重回文数\n",i);
}
