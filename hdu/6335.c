#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
ll n,m,a[105],b[105],sum[105];
int comp(const void*a,const void*b){
	return *(int*)a-*(int*)b;
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		int i;
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++){
			scanf("%lld%lld",&a[i],&b[i]);
			sum[i]=a[i]+b[i];
		}
//		for(i=0;i<n;i++){
//			printf("%lld ",sum[i]);
//		}
		qsort(sum,n,sizeof(ll),comp);
//		for(i=0;i<n;i++){
//			printf("%lld ",sum[i]);
//		}
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
