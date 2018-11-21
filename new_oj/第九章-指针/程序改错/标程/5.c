#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void strcpy_m(char *s1,char *s2,int m){
	int len=strlen(s1),now=0;
	if(len<m){
		s2[0]=0;
		return;
	}
	for(int i=m-1;i<len;i++){
		s2[now++]=s1[i];
		s2[now]=0;
	}
}

int main(){
	char *s1=(char*)malloc(sizeof(char)*10),*s2=(char*)malloc(sizeof(char)*10);
	int m;
	scanf("%s%d",s1,&m);
	strcpy_m(s1,s2,m);
	printf("%s\n",s2);
}