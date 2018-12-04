#include<stdio.h>

int main()
{
	int a[11]={1,4,6,9,13,16,19,28,40,100};
	int i,n;
	scanf("%d",&n);
	for(i=9;n<a[i] && i>=0;i--)
		a[i+1]=a[i];
	a[i+1]=n;
	for(i=0;i<11;i++)
		printf("%d\n",a[i]);
}
