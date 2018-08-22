//反复提交会在tle和ac之间徘徊

#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
//using namespace std;
typedef long long ll;

ll n,m,k,t,ans,dp[85][85][85*85];
ll dfs(ll x,ll y,ll z){
	if(dp[x][y][z]!=-1){
		return dp[x][y][z];
	}
	ll tmp=0;
	if(x<n){
		tmp=(tmp+y*(n-x)%k*dfs(x+1,y,z+1))%k;
	}
	if(y<m){
		tmp=(tmp+x*(m-y)%k*dfs(x,y+1,z+1))%k;
	}
	if(x*y>z){
		tmp=(tmp+(x*y-z)%k*dfs(x,y,z+1))%k;
	}
	return dp[x][y][z]=tmp;
}
int main(){
	scanf("%lld",&t);
	while(t--){
		memset(dp,-1,sizeof(dp));
		scanf("%lld%lld%lld",&n,&m,&k);
		dp[n][m][n*m]=1;
		ans=m*n%k*dfs(1,1,1)%k;
		printf("%lld\n",ans);
	}
}
