#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n,*num;

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);
		num=(int*)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		for(int i=n-1;i>=0;i--){
			printf("%d%c",num[i]," \n"[i==0]);
		}
	}
}