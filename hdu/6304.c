#include <stdio.h>
//#define max 1000005
//#define mod 1000000007
//typedef long long ll;
typedef long long ll;
ll n,ans,num;
const ll mod=1e9+7;

ll bit(ll a){
	if(a%2==1){
		return 1;
	}
	return bit(a>>1)+1;
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
//		num[1]=2;
//		for(int i=2;i<max;i++){
//			num[i]=num[i-1]+bit(i);
//			printf("f[%d]=%lld\n",i,num[i]);
//			if(num[i]/2>i){
//				break;
//			}
//		}
		num=1;
		ans=1;
		scanf("%lld",&n);
		ll until=n/2;
		for(ll step=1;step<=until;step*=2){
			ll sw=(step+(until-until%step)),xs=until/step;
			if(step>1){
				ans=(ans+(((sw/2)%mod)*(xs%mod))%mod)%mod;
			}
			else{
				if(sw%2==0){
					ans=(ans+(((sw/2)%mod)*(xs%mod))%mod)%mod;
				}
				else{
					ans=(ans+((sw%mod)*((xs/2)%mod))%mod)%mod;
				}
			}
			num+=(until/step);
		}
		if(num>n){
			printf("fuck!!!!!\n");
		}
		while(num<n){
			ll wei=bit(++until);
			if(num+wei>n){
				break;
			}
			else{
				ll add_ans=(wei*(until%mod))%mod;
				ans=(ans+add_ans)%mod;
				num+=wei;
			}
		}
		ll add_ans=((n-num)*(until%mod))%mod;
		ans=(ans+add_ans)%mod;
		printf("%lld\n",ans);
	}
}
