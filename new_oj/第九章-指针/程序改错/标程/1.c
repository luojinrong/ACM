#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
	int t=*a;*a=*b;*b=t;
}

int main(){
	int n,**matrix;
	scanf("%d",&n);
	matrix=(int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++){
		matrix[i]=(int*)malloc(sizeof(int)*n);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			swap(&matrix[i][j],&matrix[j][i]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}