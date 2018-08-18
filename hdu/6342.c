#include <stdio.h>
#include <string.h>
int len;
char s[505];

int check(){
	if(s[0]=='*'||s[0]=='+'||(s[0]=='0'&&s[1]>='0'&&s[1]<='9')){
		return 0;
	}
	if(s[len-1]=='+'||s[len-1]=='*'){
		return 0;
	}
	for(int i=1;i<len;i++){
		if((s[i]=='+'||s[i]=='*')&&(s[i+1]=='+'||s[i+1]=='*')){
			return 0;
		}
		if((s[i]=='+'||s[i]=='*')&&(s[i+1]=='0')&&(s[i+2]>='0'&&s[i+2]<='9')){
			return 0;
		}
	}	
	return 1;
}

void change(){
	for(int i=0;i<len;i++){
		if(s[i]=='?'){
			s[i]='1';
		}
		if(!check()){
			s[i]='+';
		}
		if(!check()){
			return;
		}
	}
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%s",s);
		len=strlen(s);
		if(!check()){
			printf("IMPOSSIBLE\n");
		}
		else{
			change();
			if(check()){
				printf("%s\n",s);
			}
			else{
				printf("IMPOSSIBLE\n");
			}
		}
	}
}
