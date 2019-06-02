#include<stdio.h>
#include<string.h>
typedef long long ll;
const ll maxn=1e5+5,m=1e9+7;
ll ans;
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

ll mod(){//求b%f(m)
	ll len=strlen(s),ans=0;
	for(int i=0;i<len;i++){
		ans=ans*10+(s[i]-'0');
		ans%=(m-1);
	}
	return ans;
}

int main(){
	scanf("%s",s);
	while(s[0]!='0'){
		ll t=mod();
		ans=qpow(2,t-1)*(qpow(2,t-1)+1)%m;
		printf("%lld\n",ans);
		scanf("%s",s);
	}
}
