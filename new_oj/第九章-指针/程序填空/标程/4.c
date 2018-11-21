#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);//n>2
	int **tri;
	tri=(int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++){
		tri[i]=(int*)malloc(sizeof(int)*(i+1));//①
	}
	tri[0][0]=tri[1][0]=tri[1][1]=1;
	for(int i=2;i<n;i++){
		tri[i][0]=tri[i][i]=1;//②
		for(int j=1;j<i;j++){
			tri[i][j]=tri[i-1][j-1]+tri[i-1][j];//③
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			printf("%d%c",tri[i][j]," \n"[j==i]);
		}
	}
	for(int i=0;i<n;i++){
		free(tri[i]);
	}
	free(tri);//④
}