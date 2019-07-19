#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn(1e3+5),maxa(1e5+5),mod(998244353);
const double pi=acos(-1);
ll n,k,a[maxn],dp[maxa],ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(ll i=1;i*(k-1)<maxa;i++){
		ll dpp[maxn][maxn],now;
		for(ll j=0;j<=k;j++){
			for(ll p=0;p<n;p++){
				dpp[j][p]=0;
			}
		}
		for(ll p=0;p<n;p++){
			dpp[1][p]=p+1;
		}
		for(ll j=2;j<=k;j++){
			now=0;
			for(ll p=j-1;p<n;p++){
				for(;now<p;now++){
					if(dpp[j-1][now]&&(a[p]-a[now])>=i&&(a[p]-a[now+1])<i){
						dpp[j][p]=(dpp[j-1][now]+dpp[j][p-1])%mod;
						break;
					}else if(a[p]-a[now]<i){
						break;
					}
				}
			}
		}
		ans+=dpp[k][n-1]%mod;
	}
	cout<<ans%mod<<endl;
}
