#include<bits/stdc++.h>
#define FIN freopen("./*.in","r",stdin)
#define debug(x) cout<<#x"=["<<x<<"]"<<endl
using namespace std;
typedef long long ll;
const ll maxn(1e5+5);
const double pi=acos(-1);
ll n,a[maxn];
string s;
int main(){
#ifndef ONLINE_JUDGE
	FIN;
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,[](ll a,ll b){return a>b;});//降序
}
