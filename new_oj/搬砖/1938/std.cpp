#include<stdio.h>

int main()
{	
	int a,i,b;
	scanf("%d",&a);
	for(i=2;i<=10;i++)
	{
		a=(a+1)*2;
	}
	printf("第一天共摘了%d个桃子",a);
}
