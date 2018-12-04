#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	char a[50];
	int len,i,num=0,Isfirst=1,numb=0,b,j,s=0,h=0;
	scanf("%s",a);
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]=='.')
			num++;
		if(a[i]=='-')
		{ h=1;		break;}
	}
	if(num==3&&h==0)
	{
		a[len]='.';
		for(i=0;i<=len;i++)
		{
			numb=0;
			if(a[i]>='0'&&a[i]<='9'&&Isfirst)
			{
				b=i;
				Isfirst=0;
			}
			else if(a[i]=='.'&&Isfirst==0)
			{
				if(i-b<=3)
				{
					for(j=i-b-1;j>=0;j--)
					numb+=(a[i-1-j]-'0')*pow(10,j);
				}
				if(numb>=0&&numb<=255)
					s++;	
				if(s==4) printf("YES\n");
					Isfirst=1;
			}
		}
	}
	if(s!=4)
		printf("NO\n");
	return 0;
}
