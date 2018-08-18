#include <stdio.h>
#define maxn 100
typedef long long ll;

ll f[maxn],a,b,c,d,p,n;

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&p,&n);
		f[1]=a;
		f[2]=b;
		for(ll i=3;i<=n;i++){
			f[i]=c*f[i-2]+d*f[i-1]+p/i;
		}
		for(ll i=1;i<=n;i++){
			printf("F[%lld]=%lld\n",i,f[i]);
		}
	}
}
