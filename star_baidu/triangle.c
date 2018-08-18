#include <stdio.h>
#include <stdlib.h>
#define maxn 1005
typedef long long ll;

ll a[maxn],N,pos;
int cmp(const void*a,const void*b){
	return *(int*)b-*(int*)a;
}

int main(){
	while(~scanf("%lld",&N)){
		pos=-1;
		for(ll i=0;i<N;i++){
			scanf("%lld",&a[i]);
		}
		qsort(a,N,sizeof(ll),cmp);
		for(ll i=0;i<N-2;i++){
			if(a[i]<a[i+1]+a[i+2]){
				pos=i;
				break;
			}
		}
		if(pos==-1){
			printf("-1\n");
		}
		else{
			printf("%lld\n",a[pos]+a[pos+1]+a[pos+2]);
		}
	}
}
