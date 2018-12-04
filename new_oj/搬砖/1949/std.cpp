#include<stdio.h>

int main()
{
	char a;
	int letter=0,space=0,digit=0,other=0;
	while((a=getchar())!='\n')
	{
		//printf("%c\n",a);
		if((a>='A'&&a<='Z')||(a>='a'&&a<='z'))//||(a>=0x81&&a<=0xFE&& (a+1)>=0x40&&(a+1)<=0xFE))
			letter++;
		else if(a>='0'&&a<='9')
		    digit++;
	    else if(a==' ')
		    space++;
	    else//(a!=' '&&(a<'0'||a>'9')&&((a>='z'||a<'a')||(a>'Z'||a<'A')))
			other++;
	}
	printf("%d,%d,%d,%d\n",letter,space,digit,other);
}
