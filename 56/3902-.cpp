//#include<iostream>
//using namespace std;
//typedef long long ll;
//const ll mod=1e9+7;
//ll ans[15];
//
//ll modd(ll n){
//	return n%(mod-1);
//}
//
//ll qpow(ll a,ll b){
//	ll r=1,base=a;
//	while(b){
//		if(b%2){
//			r=r*base%mod;
//		}
//		base=base*base%mod;
//		b>>=1;
//	}
//	return r%mod;
//}
//
//int main(){
//	ans[1]=2;
//	for(int i=2;i<15;i++){
//		ans[i]=qpow(2,modd(ans[i-1]));
//	}
//	for(int i=1;i<15;i++){
//		cout<<ans[i]<<endl;
//	}
//}
//a^b%m=a^(b%f(m))
//其中 f(m) 为欧拉函数
//

#include<stdio.h>
#include<string.h>
typedef long long ll;
const ll maxn=1e5+5,m=1e9+7;
char s[100005];
ll qpow(ll a,ll b){//快速幂
	ll r=1,base=a;
	while(b){
		if(b%2){
			r=r*base%m;
		}
		base=base*base%m;
		b>>=1;
	}
	return r;
}

ll mod(ll n){//求b%f(m)
	n%=(m-1);
}

int main(){
	scanf("%s",s);
	printf("%lld\n",qpow(2,mod(t)));
}
