#include<stdio.h>
#include<stdlib.h>

const int inf=0xfffffff;

int n,*a,max,smax;

void select(){
	for(int i=0;i<n;i++){
		if(max<a[i]){
			smax=max;
			max=a[i];
		}
		else if(smax<a[i]){
			smax=a[i];
		}
	}
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		max=smax=-inf;
		scanf("%d",&n);
		a=(int*)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		select();
		printf("%d %d\n",max,smax);
		free(a);
	}
}