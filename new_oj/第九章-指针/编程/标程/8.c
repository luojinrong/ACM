#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[105];
int n;

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%s%d",s,&n);
		int len=strlen(s);
		if(n<len){
			char *tmp=(char*)malloc(sizeof(char)*(n+1));
			for(int i=0;i<n;i++){
				tmp[i]=s[i];
			}
			tmp[n]=0;
			for(int i=0;i<len-n+1;i++){
				s[i]=s[i+n];
			}
			strcat(s,tmp);
		}
		printf("%s\n",s);
	}
}