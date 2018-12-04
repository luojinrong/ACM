#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,u,v,a[100],b[100];
	char n[1000],max,min;
	scanf("%s",n);
	max=n[0];min=n[0];
	for(i=0;i<strlen(n);i++)
	{
		if(n[i]>=max)
		{
			max=n[i];		
			u=n[i];
		}	
		if(n[i]<=min)
		{
			min=n[i];
			v=n[i];
		}	 
	}    
	for(i=0;i<strlen(n);i++)
	{
		if(n[i]!=u&&n[i]!=v)
		printf("%c",n[i]);
	}
}
