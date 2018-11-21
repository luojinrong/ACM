#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char *s=(char*)malloc(sizeof(char)*100),c;
	scanf("%s %c",s,&c);
	int step=0,now=0;
	for(int i=0;i<strlen(s);i++){
		if(s[i]!=c){
			s[step++]=s[i];
		}
	}
	s[step]=0;
	printf("%s",s);
}