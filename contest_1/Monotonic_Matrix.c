#include<stdio.h>
#include<string.h>
int n,m;
int num[100005],flag[100005];

int main(){
	while(scanf("%d%d",&n,&m)){
		int i;
		for(i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		while(m--){
			int l,r,count=0;
			memset(flag,0,sizeof(flag));
			scanf("%d%d",&l,&r);
			for(i=0;i<=l-1;i++){
				if(!flag[num[i]]){
					count++;
					flag[num[i]]=1;
				}
			}
			for(i=r-1;i<=n-1;i++){
				if(!flag[num[i]]){
					count++;
					flag[num[i]]=1;
				}	
			}
			printf("%d\n",count);
		}
	}
}
