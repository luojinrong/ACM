#include<bits/stdc++.h>
#define FIN freopen("./1004.in","r",stdin)
#define debug(x) cout<<#x"=["<<x<<"]"<<endl
using namespace std;
typedef long long ll;
const ll maxn(1e5+5);
const double pi=acos(-1);
struct car{
	ll l,s,v;
	double t;
}c[maxn];
double ans;
ll n,sum[maxn];
int main(){
#ifndef ONLINE_JUDGE
	FIN;
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n){
		ans=0;
		sum[0]=0;
		for(ll i=1;i<=n+1;i++){
			cin>>c[i].l;
			sum[i]=sum[i-1]+c[i].l;
		}
		for(ll i=1;i<=n+1;i++){
			cin>>c[i].s;
			c[i].s+=sum[i]-c[1].l;
		}
		for(ll i=1;i<=n+1;i++){
			cin>>c[i].v;
			c[i].t=(c[i].s+0.0)/c[i].v;
			ans=max(ans,c[i].t);
		}
		cout<<fixed<<setprecision(10)<<ans<<endl;
	}
}
