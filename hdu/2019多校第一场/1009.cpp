#include<bits/stdc++.h>
#define FIN freopen("./1009.in","r",stdin)
#define debug(x) cout<<#x"=["<<x<<"]"<<endl
using namespace std;
typedef long long ll;
const ll maxn(1e5+5);
char mincan;
const double pi=acos(-1);
ll n,l[30],r[30],k,back[30][maxn],net[30][maxn],idx,flag;
string s,ans;
bool check(ll c){
	ll pos=net[c][idx+1],ss=0,flag=1;
	if(pos==-1){
		return false;
	}
	if(r[c]==0){
		return false;
	}
	for(ll i=1;i<=26;i++){
		if(back[i][pos]<l[i]){
			flag=0;
		}
		ss+=l[i];
	}
	ss-=(l[c]!=0);
	if(ss>k-1){
		flag=0;
	}
	if((ll)s.length()-pos<k-1){
		flag=0;
	}
	return flag;
}
int main(){
#ifndef ONLINE_JUDGE
	FIN;
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin>>s>>k){
		n=s.length();
		ans.clear();
		idx=-1;
		for(ll i=1;i<=26;i++){
			cin>>l[i]>>r[i];
			back[i][n]=0;
			net[i][n]=-1;
		}
		for(ll i=n-1;i>=0;i--){
			for(ll j=1;j<=26;j++){
				back[j][i]=back[j][i+1];
				net[j][i]=net[j][i+1];
			}
			back[s[i]-'a'+1][i]++;
			net[s[i]-'a'+1][i]=i;
		}
		while(k){
			flag=0;
			for(ll i=1;i<=26;i++){
				if(check(i)){
					flag=1;
					ans+='a'+i-1;
					k--;
					l[i]=max(l[i]-1,0ll);
					r[i]=max(r[i]-1,0ll);
					idx=net[i][idx+1];
					break;
				}
			}
			if(!flag){
				break;
			}
		}
		if(flag){
			cout<<ans<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
}
