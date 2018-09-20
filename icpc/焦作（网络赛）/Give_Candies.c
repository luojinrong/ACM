#include<stdio.h>
#include<string.h>
typedef long long ll;
const ll maxn=1e5+5,m=1e9+7;
char s[100005];
ll qpow(ll a,ll b){
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

ll mod(){
	ll len=strlen(s),ans=0;
	for(int i=0;i<len;i++){
		ans=ans*10+(s[i]-'0');
		ans%=(m-1);
	}
	return ans;
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%s",s);
		ll t=mod();
		if(t==0){
			t=1e9+5;
		}
		else{
			t--;
		}
		printf("%lld\n",qpow(2,t));
	}
}
