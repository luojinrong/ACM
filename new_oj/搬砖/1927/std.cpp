#include <stdio.h>
#include <math.h>

int main()
{
	double a,b,c;
	double s;
	double x,y;
	scanf("%lf%lf%lf",&a,&b,&c);
	s=(a+b+c)/2;
	y=a+b+c;
	if(a+b>c && a+c>b && b+c>a)
	{
		x=sqrt(s*(s-a)*(s-b)*(s-c));
		printf("%.2lf %.2lf",x,y);
	}
	else
		printf("There sides do not correspond to a valid triangle\n");
	return 0;
}
