#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int comp(const void *a,const void *b){
	return (*(int*)a)-(*(int*)b);
}

int main(){
	int *a,i;
	a=(int*)malloc(sizeof(int)*10);
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	/*for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}*/
	qsort(a,10,sizeof(int),comp);
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
}
