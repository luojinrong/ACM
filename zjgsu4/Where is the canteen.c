#include<stdio.h>
int n,m;
char map[20][20];
int fc[250][250];
int dp[250];//未知数的值
int free_x[250];//当值为1时该未知数解出
int st_x,st_y;

int main(){
	while(scanf("%d%d",&n,&m)){
		int i,j;
		memset(free_x,0,sizeof(free_x));
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@'){
					st_x=i;
					st_y=j;
				}
				else if(map[i][j]=='$'){
					dp[i*m+j]=0;
					free_x[i*m+j]=1;	
				}
			}
		}
		
	}
}
