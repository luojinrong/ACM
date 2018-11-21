#include<stdio.h>
#include<stdlib.h>
int main(){
	char *s, *match;
	int rear=0, i, flag=1;
	s = (char*)malloc(sizeof(char)*105);
	match = (char*)malloc(sizeof(char)*105);
	gets(s);//①
	for(i=0;*(s+i);i++){
		if(*(s+i)=='('){
			*(match+rear++)='(';//②
		}
		else if(rear>0){//③
			rear--;
		}
		else{
			flag=0;
			break;//④
		}
	}
	if(flag==1&&rear>0){//⑤
		flag=0;
	}
	printf("%s\n",flag?"match succeed":"match failed");
}