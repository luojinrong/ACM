#include<stdio.h>
#include<stdlib.h>

int m,n,**matrix,*sum;

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%d%d",&m,&n);
		matrix=(int**)malloc(sizeof(int*)*m);
		for(int i=0;i<m;i++){
			matrix[i]=(int*)malloc(sizeof(int)*n);
		}
		sum=(int*)malloc(sizeof(int)*m);
		memset(sum,0,sizeof(int)*m);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&matrix[i][j]);
				sum[i]+=matrix[i][j];
			}
		}
		for(int i=0;i<m;i++){
			printf("%d%c",sum[i]," \n"[i==m-1]);
		}
	}
}