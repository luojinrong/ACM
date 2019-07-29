#include<bits/stdc++.h>
#define FIN freopen("./K.in","r",stdin)
#define debug(x) cout<<#x"=["<<x<<"]"<<endl
using namespace std;
typedef long long ll;
const ll maxn(1e5+5);
const double pi=acos(-1);
ll len,dp[3][maxn],sum[maxn],ans;
string s;
int main(){
#ifndef ONLINE_JUDGE
	FIN;
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	len=s.length();
	sum[0]=s[0]-'0';
	dp[(s[0]-'0')%3][0]=1;
	for(ll i=1;i<len;i++){
		if((s[i]-'0')%3==0){
			dp[0][i]=dp[0][i-1]+1;
			dp[1][i]=dp[1][i-1];
			dp[2][i]=dp[2][i-1];
		}else if((s[i]-'0')%3==1){
			dp[0][i]=dp[2][i-1];
			dp[1][i]=dp[0][i-1]+1;
			dp[2][i]=dp[1][i-1];
		}else{
			dp[0][i]=dp[1][i-1];
			dp[1][i]=dp[2][i-1];
			dp[2][i]=dp[0][i-1]+1;
		}
	}
	ll flag=0,pre0=1,pre0num=0;
	for(ll i=0;i<len;i++){
		if(pre0==1&&s[i]=='0'){
			pre0num++;
		}
		if(pre0==1&&s[i]!='0'){
			ans+=(pre0num+1)*pre0num/2;
			pre0=0;
		}
		if(pre0==0&&s[i]=='0'){
			flag++;
		}
		if(pre0==0&&s[i]!='0'&&flag){
			if(flag>=2){
				if(dp[0][i-1]-flag>0){
					ans+=(dp[0][i-1]-flag)*(flag-1);
				}
				ans+=(1+flag)*flag/2;
			}else{
				ans++;
			}
			flag=0;
		}
	}
	if(pre0){
		ans+=(pre0num+1)*pre0num/2;
	}
	if(flag>=2){
		if(dp[0][len-1]-flag>0){
			ans+=(dp[0][len-1]-flag)*(flag-1);
		}
		ans+=(1+flag)*flag/2;
	}
	cout<<ans<<endl;
}
