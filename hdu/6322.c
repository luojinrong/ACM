#include<stdio.h>
int n;
int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);
		if(n==1){
			printf("%d\n",5);
		}
		else{
			printf("%d\n",5+n);
		}
	}
}
