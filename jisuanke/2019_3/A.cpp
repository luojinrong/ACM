#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,a[maxn],now[maxn],max_l,ans,tmp;
int lis(int len){
	int dp[maxn],max_t=0;
	for(int i=0;i<len;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(now[j]<now[i]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		max_t=max(dp[i],max_t);
	}
	return max_t;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		now[i]=a[i];
	}
	max_l=lis(n);
	for(int i=0;i<n;i++){
		int pos=0;
		for(int j=0;j<n;j++){
			if(j!=i){
				now[pos++]=a[j];
			}
		}
		tmp=lis(n-1);
		if(tmp<max_l){
			ans++;
		}
	}
	cout<<ans<<"\n";
}
