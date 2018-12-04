#include<stdio.h>

char file_in[100]="./data/0.in";
char file_out[100]="./data/0.out";

int main()
{
	for(int f=0;f<10;f++){
		file_in[7]=f+'0';
		file_out[7]=f+'0';
		freopen(file_in,"r",stdin);
		freopen(file_out,"w",stdout);
		int n,i,j,str[30][30];
		while(scanf("%d",&n),n!=0)
		{
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
				{
					str[i][0]=1;
					str[i][i]=1;
				}
				for(i=2;i<n;i++)
					for(j=1;j<=i-1;j++)
						str[i][j]=str[i-1][j-1]+str[i-1][j];
				for(i=0;i<n;i++)
				{
					for(j=0;j<=i;j++)
					{
						if(j!=i)
							printf("%d ",str[i][j]);
						if(j==i)
							printf("%d",str[i][j]);
					}
					printf("\n");
				}
				printf("\n");
		}
	}
	return 0;
}
