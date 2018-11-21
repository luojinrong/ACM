#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void strcat_n(char *s1,char *s2,int n){
	int len=strlen(s1);
	for(int i=0;i<n;i++){
		if(!s2[i]){
			break;
		}
		s1[len++]=s2[i];
		s1[len]=0;
	}
}

int main(){
	char *s1=(char*)malloc(sizeof(char)*205),*s2=(char*)malloc(sizeof(char)*105);
	int n;
	scanf("%s%s%d",s1,s2,&n);
	strcat_n(s1,s2,n);
	printf("%s\n",s1);
}