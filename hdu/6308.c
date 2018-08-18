#include <stdio.h>
#include <string.h>
#include <math.h>
int a,b;
char str[10];

float char_to_int(char str[10]){
	int len=strlen(str);
	int flag=0;
	float t_z=0;
	for(int i=4;i<len;i++){
		if(str[i]>='0'&&str[i]<='9'){
			t_z=t_z*10+str[i]-'0';
		}
		else{
			flag=strlen(str)-i-1;
		}
	}
	t_z/=pow(10,flag);
	if(str[3]=='-'){
		t_z*=-1;
	}
	return t_z-8;
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%d%d%s",&a,&b,str);
		float sc=char_to_int(str);
		if(sc<0){
			b+=(int)(60*sc-0.5);
		}
		else{
			b+=(int)(60*sc+0.5);
		}
		while(b<0){
			b+=60;
			a-=1;
		}
		while(b>=60){
			b-=60;
			a+=1;
		}
		while(a<0){
			a+=24;
		}
		while(a>=24){
			a-=24;
		}
		printf("%02d:%02d\n",a,b);
	}
}
