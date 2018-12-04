#include<stdio.h>

int main()  
{  
	char f;  
	int b,c,d,e,i;  
	b=0,c=0,d=0,e=0;  
	for(i=0;i<20;i++)  
	{  
		f=getchar();  
		if((f>='a'&&f<='z')||(f>='A'&&f<='Z'))  
			b++;  
		else if(f>='0'&&f<='9')  
			c++;  
		else if(f==' '||f=='\n')  
			d++;  
		else e++;  
	}  
	printf("%d个英文字母\n",b);  
	printf("%d个数字字符\n",c);  
	printf("%d个空格或回车\n",d);  
	printf("%d个其他字符\n",e);   
	return 0; 
}    
