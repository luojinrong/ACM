#include<bits/stdc++.h>
#define FIN freopen("./H.in","r",stdin)
#define debug(x) cout<<#x"=["<<x<<"]"<<endl
using namespace std;
typedef long long ll;
const ll maxn(1e3+5);
const double pi=acos(-1);
const double eps(1e-6);
ll T,n,a[maxn],maxx,maxy,minx,miny;
struct node{
	ll x,y;
}p[maxn],ans[2];
bool cmp(node n1,node n2){
	return (n1.x==n2.x?n1.y<n2.y:n1.x<n2.x);
}
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
		for(int i=1;i<=n;i++){
			cin>>p[i].x>>p[i].y;
		}
		sort(p+1,p+n+1,cmp);
		if(p[n/2].x<p[n/2+1].x){
			ans[0].x=p[n/2].x;
			ans[1].x=p[n/2].x+1;
			ans[0].y=1e9-1e6;
			ans[1].y=1e6-1e9;
		}else{
			ans[0].x=p[n/2].x-1;
			ans[1].x=p[n/2].x+1;
			ans[0].y=p[n/2].y+1e9-1e6+1;
			ans[1].y=p[n/2].y-1e9+1e6;
		}
		cout<<ans[0].x<<" "<<ans[0].y<<" "<<ans[1].x<<" "<<ans[1].y<<"\n";
	}
}
