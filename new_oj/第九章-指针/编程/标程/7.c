#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[105],c;
int n;

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%s %c%d",s,&c,&n);
		int len=strlen(s);
		if(len<=n){
			for(int i=0;i<len;i++){
				s[i]=c;
			}
		}
		else{
			for(int i=0;i<n;i++){
				s[i]=c;
			}
		}
		printf("%s\n",s);
	}
}