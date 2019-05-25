#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn(2e5+5);
ll order[maxn],n,m,ans,ordered[maxn],total,buy;
vector<ll> v[maxn<<1];

bool check(ll money){
	buy=0;
	ll s=0;
	for(ll i=1;i<=n;i++){
		ordered[i]=order[i];
	}
	for(ll i=money;i>0;i--){
		for(ll j=0;j<v[i].size();j++){
			if(ordered[v[i][j]]&&money){
				ll tmp=min(ordered[v[i][j]],money);
				ordered[v[i][j]]-=tmp;
				money-=tmp;
				buy+=tmp;
			}
		}
		if(money>=i){
			s++;
			money--;
		}
	}
	return s/2>=total-buy;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>order[i];
		total+=order[i];
	}
	for(ll i=0;i<m;i++){
		ll tmp_d,tmp_t;
		cin>>tmp_d>>tmp_t;
		v[tmp_d].push_back(tmp_t);
	}
	ll l=total,r=total*2,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans<<"\n";
}
