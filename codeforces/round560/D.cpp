#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn(305);
ll t,n,d[maxn],ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=0;i<n;i++){
			cin>>d[i];
		}
		sort(d,d+n);
		if(n%2){
			ans=d[n/2]*d[n/2];
		}
		else{
			ans=d[n/2]*d[n/2-1];
		}
		for(ll i=0;i<n/2;i++){
			if(d[i]*d[n-1-i]!=ans){
				ans=-1;
				break;
			}
		}
		if(ans!=-1){
			ll tmp=ll(sqrt(ans)),num=0;
			if(tmp*tmp==ans){
				num=1;
				tmp--;
			}
			for(ll i=2;i<=tmp;i++){
				if(ans%i==0){
					num+=2;
				}
			}
			if(num!=n){
				ans=-1;
			}
		}
		cout<<ans<<endl;
	}
}
