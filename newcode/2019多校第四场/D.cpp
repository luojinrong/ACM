#include<bits/stdc++.h>
#define FIN freopen("./D.in","r",stdin)
#define debug(x) cout<<#x"=["<<x<<"]"<<endl
using namespace std;
typedef long long ll;
const ll maxn(1e2+5);
const double pi=acos(-1);
ll n,mod[3][maxn],num[3],ans[2],T;
int main(){
#ifndef ONLINE_JUDGE
	FIN;
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		memset(ans,0,sizeof(ans));
		num[1]=num[2]=0;
		cin>>n;
		if(n%3==0){
			cout<<1<<" "<<n<<endl;
			continue;
		}
		for(ll i=0;i<=60;i++){
			if((n&(1ll<<i))){
				mod[(1ll<<i)%3][num[(1ll<<i)%3]++]=1ll<<i;
			}
		}
		if(num[1]>=1&&num[2]>=1){
			ans[0]+=mod[1][0]+mod[2][0];
			for(ll i=1;i<num[1];i++){
				ans[1]+=mod[1][i];
			}
			for(ll i=1;i<num[2];i++){
				ans[1]+=mod[2][i];
			}
			if(ans[1]%3==1){
				ans[1]+=mod[2][0];
			}else if(ans[1]%3==2){
				ans[1]+=mod[1][0];
			}
		}else if(num[1]>=3){
			ans[0]+=mod[1][0]+mod[1][1]+mod[1][2];
			for(ll i=3;i<num[1];i++){
				ans[1]+=mod[1][i];
			}
			if(ans[1]%3==1){
				ans[1]+=mod[1][0]+mod[1][1];
			}else if(ans[1]%3==2){
				ans[1]+=mod[1][0];
			}
		}else if(num[2]>=3){
			ans[0]+=mod[2][0]+mod[2][1]+mod[2][2];
			for(ll i=3;i<num[2];i++){
				ans[1]+=mod[2][i];
			}
			if(ans[1]%3==1){
				ans[1]+=mod[2][0];
			}else if(ans[1]%3==2){
				ans[1]+=mod[2][0]+mod[2][1];
			}
		}
		cout<<"2 "<<ans[0]<<" "<<ans[1]<<endl;
	}
}
