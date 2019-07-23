#include<bits/stdc++.h>
using namespace std;
#define FIN freopen("./C.in","r",stdin)
#define debug(x) cout<<#x"=["<<x<<"]"<<endl
typedef long long ll;
const ll maxn(1e4+5);
const double pi=acos(-1);
ll n,m,a[maxn];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
#ifndef ONLINE_JUDGE
	FIN;
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n>>m){
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1,cmp);
		ll idx=n,left=m;
		for(ll i=1;i<n;i++){
			if(left>=abs(a[i+1]-a[i])*i){
				left-=abs(a[i+1]-a[i])*i;
			}else{
				idx=i;
				break;
			}
		}
		ll n1=(a[idx]*idx-left)*(a[idx]*idx-left),n2=idx*m*m;
		for(ll i=idx+1;i<=n;i++){
			n1+=a[i]*a[i]*idx;
		}
		ll g=__gcd(n1,n2);
		if(g==n2){
			cout<<n1/n2<<endl;
		}else{
			cout<<n1/g<<"/"<<n2/g<<endl;
		}
	}
}
