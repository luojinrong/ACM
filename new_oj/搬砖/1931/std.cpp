#include<stdio.h>

int main()
{
	char a;
	scanf("%c",&a);
	if(a>='A'&&a<='Z')
	printf("输入的是一个大写字母");
	else printf("输入的不是一个大写字母");
	return 0; 
}
