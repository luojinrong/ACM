#include<stdio.h>
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
typedef long long ll;

ll a,b,c,d,v,t,timer,counter,sta,lcm,a_t,c_t;

ll GCD(ll m,ll n){
	return m%n==0?n:GCD(n,m%n);
}

void pre(){
	lcm=a*c/GCD(a,c);
	if(a>c){
		a^=c;c^=a;a^=c;
		b^=d;d^=b;b^=d;
	}
}

void bl(ll e){
	for(ll i=0;i<e;){
		if((min((a_t+a),(c_t+c)))<=i+v){
			i=min(a_t+a,c_t+c);
			if(a_t+a<c_t+c){
				a_t+=a;
				if(a_t>e){
					break;
				}
				counter+=b;
			}
			else if(a_t+a>c_t+c){
				c_t+=c;
				if(c_t>e){
					break;
				}
				counter+=d;
			}
		}
		else{
			i=min(a_t+a,c_t+c);
			if(a_t+a<c_t+c){
				a_t+=a;
				if(a_t>e){
					break;
				}
				counter+=(b-1);
			}
			else if(a_t+a>c_t+c){
				c_t+=c;
				if(c_t>e){
					break;
				}
				counter+=(d-1);
			}
		}
	}
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		a_t=c_t=counter=0;
		scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&v,&t);
		pre();
		if(v>=a){
			counter=(t/a+1)*b+(t/c+1)*d-1;
			printf("%lld\n",counter);
		}
		else{
			counter+=(b+d-1);
			sta=1;
			bl(lcm);
			counter*=(t/lcm);
			a_t=c_t=0;
			counter+=(b+d-1);
			bl(t%lcm);
			printf("%lld\n",counter);
		}
	}
}
