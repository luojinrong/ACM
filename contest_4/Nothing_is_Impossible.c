#include <stdio.h>
#include <stdlib.h>

int n,m,a[105],b[105],sum[105];
int comp(const void*a,const void*b){
	return *(int*)a-*(int*)b;
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		int i;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%d%d",&a[i],&b[i]);
			sum[i]=a[i]+b[i];
		}
		qsort(sum,n,sizeof(int),comp);
		for(i=0;i<n;i++){
			printf("%d ",sum[i]);
		}
		int all=1;
		for(i=0;i<n;i++){
			if(all*sum[i]>m){
				break;
			}
			else{
				all*=sum[i];
			}
		}
		printf("%d\n",i);
	}
}
