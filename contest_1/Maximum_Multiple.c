#include<stdio.h>
typedef long long ll;
int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		ll n;
		scanf("%lld",&n);
		if(!(n%3)){
			printf("%lld\n",n*n*n/27);
		}
		else if(!(n%4)){
			printf("%lld\n",n*n*n/32);
		}
		else{
			printf("-1\n");
		}
	}
}
