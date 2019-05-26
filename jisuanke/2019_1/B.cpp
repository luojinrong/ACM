#include<bits/stdc++.h>
using namespace std;
const int maxn(55);
const int mod(1e9+7);
int n,m,u[maxn],v[maxn],w[maxn],dp[maxn][maxn],ans;
int gcd(int a,int b){
	return a%b?gcd(b,a%b):b;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=m;i++){
		dp[1][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(gcd(j,k)!=w[i-1]){
					dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
				}
			}
		}
	}
	for(int i=0;i<=m;i++){
		ans=(ans+dp[n][i])%mod;
	}
	cout<<ans<<"\n";
}
