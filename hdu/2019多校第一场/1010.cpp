#include<bits/stdc++.h>
#define FIN freopen("./*.in","r",stdin)
#define debug(x) cout<<#x"=["<<x<<"]"<<endl
using namespace std;
typedef long long ll;
const ll maxn(1e2+5);
const double pi=acos(-1);
ll n,a[maxn],b[maxn],T,c[maxn];
typedef struct treenode{
	ll root;
	treenode *lson;
	treenode *rson;
}tr;
int main(){
#ifndef ONLINE_JUDGE
	FIN;
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			c[a[i]]++;
		}
		for(ll i=1;i<=n;i++){
			cin>>b[i];
			c[a[i]]++;
		}
	}
}
