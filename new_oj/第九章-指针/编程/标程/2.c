#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m,count,*cir;

int Josephus(){
	int counter=0;
	for(int i=0;count;i++){
		if(!cir[i%n]){
			counter++;
		}
		if(counter==m){
			counter=0;
			count--;
			cir[i%n]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(!cir[i]){
			return i+1;
		}
	}
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%d%d",&n,&m);
		cir=(int *)malloc(sizeof(int)*n);
		memset(cir,0,sizeof(int)*n);
		count=n-1;
		printf("%d\n",Josephus());
		free(cir);
	}
}