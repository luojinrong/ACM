#include <stdio.h>

int main()
{
	float j[10];
	int sum,a;
	float max=-1e20,min=1e20,b;
	for (a=0;a<=9;a++)
		scanf("%f",&j[a]);
	for(a=0;a<=9;a++)
	{
		if(j[a]>max)
			max=j[a];
        if(j[a]<min)
			min=j[a];
	}
	sum=j[0]+j[1]+j[2]+j[3]+j[4]+j[5]+j[6]+j[7]+j[8]+j[9]-max-min;
	b=sum/8.0;
	printf("%0.2f",b);
	return 0;
}
