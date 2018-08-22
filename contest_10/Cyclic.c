#include <stdio.h>
#include <string.h>
int n,flag[100],v[100],count;

void dfs(int now){
	if(now==1){
		v[now]=1;
		flag[v[now]]=1;
		dfs(now+1);
	}
	else if(now==n){
		for(int i=1;i<=n;i++){
			if(flag[i]==0){
				if(i!=v[now-1]+1&&i!=n){
					count++;
				}
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(flag[i]==0&&i!=v[now-1]+1){
				v[now]=i;
				flag[v[now]]=1;
				dfs(now+1);
				flag[v[now]]=0;
			}
		}
	}
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		count=0;
		memset(flag,0,sizeof(flag));
		scanf("%d",&n);
		dfs(1);
		printf("%d\n",count);
	}
}
