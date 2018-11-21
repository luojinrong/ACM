#include<stdio.h>
#include<stdlib.h>

int m,n,**matrix,max,max_x,max_y;

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%d%d",&m,&n);
		matrix=(int**)malloc(sizeof(int*)*m);
		for(int i=0;i<m;i++){
			matrix[i]=(int*)malloc(sizeof(int)*n);
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&matrix[i][j]);
				if(i==0&&j==0){
					max=matrix[i][j];
					max_x=max_y=0;
				}
				else if(matrix[i][j]>max){
					max=matrix[i][j];
					max_x=i;
					max_y=j;
				}
			}
		}
		printf("%d %d %d\n",max,max_x,max_y);
	}
}