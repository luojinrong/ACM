#include<stdio.h>
#include<string.h>

int main()
{
	char a[100],c;
	int k,n,m,i,j;
	scanf("%s",a);
	k=strlen(a);
	n=k%2;m=k/2;
	for(i=m+n;i<k;i++)
		printf("%c",a[i]);
	if(n==1)
	{
		printf("%c",a[m]);
	}
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(a[i]>a[j])
			{
				c=a[i];
				a[i]=a[j];
				a[j]=c;
			}
		}
				printf("%c",a[i]);
	}
	return 0;
}
