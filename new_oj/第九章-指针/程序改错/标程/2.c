#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reverse(char *s){
	int len=strlen(s);
	for(int i=0;i<len/2;i++){
		char c=s[i];
		s[i]=s[len-i-1];
		s[len-i-1]=c;
	}
}

void my_itoa(int i,char *s){
	if(!i){
		return;
	}
	*s=i%10+'0';
	*(s+1)=0;
	my_itoa(i/10,s+1);
}

int main(){
	char *s=(char*)malloc(sizeof(char)*10);
	int n;
	scanf("%d",&n);
	my_itoa(n,s);
	reverse(s);
	printf("%s\n",s);
}