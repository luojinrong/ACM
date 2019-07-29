#include<bits/stdc++.h>
#define FIN freopen("./1506.in","r",stdin)
#define debug(x) cout<<#x"=["<<x<<"]"<<endl
using namespace std;
typedef long long ll;
const ll maxn(1e5+5);
const double pi=acos(-1);
ll n,a[maxn],ans,root;
struct node{
	ll l,r,up;
	ll v,num;
}nodes[maxn];
ll build(ll r,ll index){
	if(nodes[index].v<nodes[r].v){
		nodes[index].num=nodes[r].num+1;
		nodes[index].l=r;
		nodes[index].up=nodes[r].up;
		if(nodes[r].up){
			if(nodes[nodes[r].up].l==r){
				nodes[nodes[r].up].l=index;
			}else{
				nodes[nodes[r].up].r=index;
			}
		}
		nodes[r].up=index;
		return index;
	}else{
		nodes[r].num++;
		if(nodes[r].r==0){
			nodes[index].num=1;
			nodes[r].r=index;
			nodes[index].up=r;
		}else{
			build(nodes[r].r,index);
		}
	}
	return r;
}
void search(ll r){
	if(r==0){
		return;
	}
	ans=max(ans,nodes[r].num*nodes[r].v);
	search(nodes[r].l);
	search(nodes[r].r);
}
int main(){
#ifndef ONLINE_JUDGE
	FIN;
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n,n){
		ans=0;
		for(ll i=1;i<=n;i++){
			cin>>nodes[i].v;
			nodes[i].l=nodes[i].r=nodes[i].up=0;
			nodes[i].num=1;
		}
		root=1;
		for(ll i=2;i<=n;i++){
			root=build(root,i);
		}
		search(root);
		cout<<ans<<endl;
	}
}
