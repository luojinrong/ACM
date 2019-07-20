#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn(1e2+5);
const ll inf(0x3f3f3f3f3f3f3f3f);
ll n,q,a[maxn],b[maxn],tmp,ans;
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n;i++){
		cin>>b[i];
	}
	cin>>q;
	while(q--){
		cin>>tmp;
		ll t;
		ans=inf;
		for(ll i=0;i<n;i++){
			t=(tmp-a[i])*(tmp-a[i])+b[i];
			if(t<ans){
				ans=t;
			}
		}
		cout<<ans<<" ";
	}
}
