#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn(2e5+5);
const ll mod(998244353);
ll n,a[maxn],b[maxn],ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		a[i]=(a[i]*(1+i)*(n-i));
	}
	for(ll i=0;i<n;i++){
		cin>>b[i];
	}
	sort(a,a+n,greater<ll>());
	sort(b,b+n,less<ll>());
	for(ll i=0;i<n;i++){
		ans=(ans+a[i]%mod*b[i]%mod)%mod;
	}
	cout<<ans<<"\n";
}
