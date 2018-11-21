#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int my_strcmp(char *s1,char *s2){
	int len=strlen(s1)>strlen(s2)?strlen(s2):strlen(s1);
	for(int i=0;i<len+1;i++){
		if((!s1[i])||(!s2[i])||s1[i]!=s2[i]){
			return s1[i]-s2[i];
		}
	}
}

int main(){
	char *s1=(char*)malloc(sizeof(char)*205),*s2=(char*)malloc(sizeof(char)*205);
	scanf("%s%s",s1,s2);
	printf("%s\n",my_strcmp(s1,s2)?"Not equal":"Equal");
}