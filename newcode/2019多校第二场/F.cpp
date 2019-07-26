#include<bits/stdc++.h>
#define FIN freopen("./F.in","r",stdin)
#define debug(x) cout<<#x"=["<<x<<"]"<<endl
using namespace std;
typedef long long ll;
const ll maxn(1e2+5);
const double pi=acos(-1);
ll n,v[maxn][maxn],ans,num1,num2,s1[maxn],s2[maxn];
void dfs(ll index,ll sum){
	if(num1==n&&num2==n){
		ans=max(sum,ans);
	}
	if(num1<n){
		ll k=0;
		s1[++num1]=index;
		for(ll i=1;i<=num2;i++){
			k+=v[s1[num1]][s2[i]];
		}
		dfs(index+1,sum+k);
		num1--;
	}
	if(num2<n){
		ll k=0;
		s2[++num2]=index;
		for(ll i=1;i<=num1;i++){
			k+=v[s2[num2]][s1[i]];
		}
		dfs(index+1,sum+k);
		num2--;
	}
}
int main(){
#ifndef ONLINE_JUDGE
	FIN;
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n*2;i++){
		for(ll j=1;j<=n*2;j++){
			cin>>v[i][j];
		}
	}
	dfs(1,0);
	cout<<ans<<endl;
}
