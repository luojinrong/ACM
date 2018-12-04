#include<stdio.h>
#include<math.h>

int prime(int d)
{
	int i=2;
	while(i++<=sqrt(d))
		if(d%i==0)
			return 0;
	return 1;
}
int main()
{
	int n,b,d,i=0;
	scanf("%d",&n);
	for(b=3;b<=(n/2);b+=2)
		if(prime(b))
		{
			d=n-b;
			if(prime(d))
			{
				if((++i)%5==1)
					printf("%d=%d+%d",n,b,d);
				else
					printf(" %d=%d+%d",n,b,d);
				if(i%5==0)
					printf("\n");
			}
		}
		printf("\n");
	return 0;
}
