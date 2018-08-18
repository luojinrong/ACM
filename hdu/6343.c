//√x+√y>√(x+y)
#include <stdio.h>
#include <math.h>
typedef long long ll;
ll a_1,a_n,n,len;
ll a[100005];
int main(){
	ll T;
	for(scanf("%lld",&T);T;T--){
		scanf("%lld",&n);
		//scanf("%lld",&a_1);
		//for(int i=1;i<n;i++){
		//	scanf("%lld",&a_n);
		//}
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		//len=sqrt(abs(a_n*1.0-a_1*1.0));
		len=sqrt(abs(a[n-1]*1.0-a[0]*1.0));
		printf("%lld\n",len);
	}
}
